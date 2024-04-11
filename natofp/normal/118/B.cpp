#include <iostream>

using namespace std;

int main()
{
   int n;
   cin>>n;
   int x=0;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<(n-i)*2;j++)
        cout<<" ";
       for(int j=0;j<i;j++)
        cout<<j<<" ";
       for(int j=i;j>=0;j--)
       {
           cout<<j;
           if(j!=0) cout<<" ";
       }

       cout<<endl;
   }
   for(int i=n;i>=0;i--)
   {
       for(int j=0;j<(n-i)*2;j++)
        cout<<" ";
       for(int j=0;j<i;j++)
        cout<<j<<" ";
       for(int j=i;j>=0;j--)
       {
           cout<<j;
           if(j!=0) cout<<" ";
       }

       cout<<endl;
   }
    return 0;
}