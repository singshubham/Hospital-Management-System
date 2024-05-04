#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
 
class patient                                   // structure
{
public:
    long long ID;
string firstname;
string lastname;
int age;
char blood[5];
char gender;
    patient*next;
};
class linkedqueue : public patient                              // class
{
patient *head,*last;
public:
linkedqueue()                                //constructor
{
head=NULL;
last=NULL;
}
    patient input();
    void insertatend();
    void insertatbeg();
    void getpatientout();
    void listofpatients();
    int search(int);
    char departmentname[50];
};
 
int linkedqueue :: search(int item)                    // search function definition
{
 if(head==NULL)                              // if list is empty 
     return false;
    else                              // if list is not empty
    {
     int flag=0;
     patient*p=new patient();
     p=head;
 
     while( p->next!=NULL && p->ID!=item )     // loop starting from head and goes till the end or p->ID found
     {
        p=p->next;                         // movement forward in list
     }
     if(p->ID==item)               // if ID is matched
     {
 	flag=1;
 	return true;
     }
     if(flag==0)                 // if ID not found
     return false;
    }
}
 
patient linkedqueue :: input()                    // input the patient details
{
    int flag=0;                                
   patient *p=new patient();                          // for adding new patient
   cout << "\n   Please enter data for patient\n";
   cout<<"\n   First name     : ";
   cin>>p->firstname;
   cout << "   Last name      : ";
   cin>>p->lastname;
   again :
   cout << "   Blood Group    : ";
   cin>>p->blood;
   if((strcmp(p->blood,"A+")==0)||(strcmp(p->blood,"a+")==0)||(strcmp(p->blood,"A-")==0)||(strcmp(p->blood,"a-")==0)||
      (strcmp(p->blood,"B+")==0)||(strcmp(p->blood,"b+")==0)||(strcmp(p->blood,"B-")==0)||(strcmp(p->blood,"b-")==0)||
      (strcmp(p->blood,"O+")==0)||(strcmp(p->blood,"o+")==0)||(strcmp(p->blood,"O-")==0)||(strcmp(p->blood,"o-")==0)||
      (strcmp(p->blood,"AB+")==0)||(strcmp(p->blood,"ab+")==0)||(strcmp(p->blood,"AB-")==0)||(strcmp(p->blood,"ab-")==0)) 
             flag=1;                           // condition for a valid blood group
    if(flag==0)
    {
        cout<<"\n   Invalid Blood Group Try Again..\n\n";
        goto again;                                // go to label
 
    }
   cout<<"   Gender(m/f)    : ";
   cin>>p->gender;
   cout<<"   Age            : ";
   cin>>p->age;
   cout<<"   Mobile number  : ";
   cin>>p->ID;
 
 
if(search(p->ID))                    // checking for p->ID
{
p->ID=0;
cout << "\n   Data not valid. Operation cancelled.";
}
return *p;
}
 
void output(patient *p)                          // display of details of patients
{
cout<<"\n   Patient data:\n";
cout<<"\n   First Name         : "<<p->firstname;
cout<<"\n   Last Name          : "<<p->lastname;
cout<<"\n   Gender             : "<<p->gender;
cout<<"\n   Age                : "<<p->age;
cout<<"\n   Blood Group        : "<<p->blood;
cout<<"\n   Mobile Number      : "<<p->ID;
}
void linkedqueue :: insertatbeg()                  // function definition to enter patient at the beginning of list
{
     patient*p=new patient();                      // for new patient
     *p=input();                                 // input function calling to enter details of patient
     if(p->ID==0)
     return;
 
     if(head==NULL)               // if no patient is already in queue
 
     {
         head=p;
         last=p;
         p->next=NULL;
     }
     else                                 // if there are patients in queue
     {
        p->next=head;
        head=p;
     }
     system("cls");
     cout << "\n\tPatient added:";
     output(p);                                      // output function called
}
void linkedqueue:: insertatend()
{
     patient*p=new patient();                    // new patient
     *p=input();                                  // input function call
     if(p->ID==0)                               // no id entered then return
     return;
 
     if(head==NULL)                            // if queue is empty
     {
     	head=p;
        last=p;
        p->next=NULL;
     }
     else                            // if queue is not empty
     {
     	p->next=NULL;
        last->next=p;
        last=p;
     }
     system("cls");
     cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
     cout <<"\n  ----------PATIENT ADDED-----------";
     output(p);
}
void linkedqueue :: getpatientout()              // function to operate and remove patient
{
 system("cls");
     if(head==NULL)                         // if queue is empty
     {
     	cout<<"\n  No Patient to operate";
     }
     else                                     // if list is not empty
     {
     	patient*p=new patient();
     	p=head;                               // first patient,s data is given
     	head=head->next;                     // first patient removed from list
    cout << "\n  Patient to operate:";
        output(p);                          // output function call to display remaining patients
 }
}
 
void linkedqueue :: listofpatients()              // display list of patients
{
     if(head==NULL)                         // if queue is empty
     {
     	cout<<"\n  No patient";
 }
      system("cls");
     cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
     patient*p=new patient;
     p=head;
     while(p!=NULL)               // loop till null appears
     {
        cout<<"\n   Patient data:\n";
cout<<"\n   First Name       : "<<p->firstname;
cout<<"\n   Last Name        : "<<p->lastname;
cout<<"\n   Gender           : "<<p->gender;
        cout<<"\n   Age              : "<<p->age;
        cout<<"\n   Blood Group      : "<<p->blood;
cout<<"\n   Mobile Number    : "<<p->ID;
cout<<"\n\n\n";
        p=p->next;
     }
     cout<<"\n";
}
 
 
void departmentmenu (linkedqueue * q)        // departmentmenu function with object(q) as arguement definition
{
    int choice = 0, success;
    patient p;
    while (choice != 5)                     // loop till option 5 chosen 
{
    system("cls");
    cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";                           // menu for the specific deparment
cout<<"\n\n   "<<q->departmentname;
cout<<"\n   [1] Add normal patient\n";
cout<<"   [2] Add critically ill patient\n";
cout<<"   [3] Take patient to Doctor\n";
cout<<"   [4] Display list\n";
cout<<"   [5] Change department or exit\n";
cout<<"\n   Please enter your choice : ";
cin>>choice;                            // input choice
 
    switch (choice)
{
  case 1:	q->insertatend();                 // insertatend() function called 
cout << "\n   Press any key";
    		getch();
 			break;
 
      case 2:	q->insertatbeg();                 // insertatbeg() function called
    		cout << "\n   Press any key";
    		getch();
break;
 
      case 3:	q->getpatientout();                 // getpatientsout() function called
 			cout<<"\n   Press any key";
     			getch();
      		break;
 
      case 4:	system("cls");
 			q->listofpatients();                 // listof patients() function called
 			cout<<"\n   Press any key";
 			getch();
break;
 }
    }
}
 
int main ()
{
    int i, choice = 0;
linkedqueue departments[4];        // object declaration of class linkedqueue
 
while(choice!=5)               // loop till choosing option 5
{
strcpy(departments[0].departmentname,"GENERAL CLINIC\n");
strcpy(departments[1].departmentname,"HEART CLINIC\n");
strcpy(departments[2].departmentname,"LUNG CLINIC\n");
strcpy(departments[3].departmentname,"PLASTIC SURGERY\n");
system("cls");                                                // clear screen after every entry
cout<<"\n  |-- HOSPITAL MANAGEMENT SYSTEM --|";
cout<<"\n \n\n";
cout<<"   Main Menu\n\n";                                     // menu displayed
for (i = 0; i < 4; i++)
{
cout<<"   "<<(i+1)<<": "<<departments[i].departmentname;         // display department's name
}
cout<<"   5: Exit";
cout<<"\n\n   Please enter your choice : ";                        // input choice from menu
cin>>choice;
if(choice>=1 && choice<=4)                   // condition for option 1 to 4
{
departmentmenu(&departments[choice-1]);             // department menu function is called
}
 
}
if(choice==5)                        // option 5 exit condition
cout<<"\n\t\tThank you! \n";
exit(0);
}
