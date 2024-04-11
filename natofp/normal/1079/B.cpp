#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s; cin>>s;
    int n=s.length();
    int k=n/20+bool(n%20);
    int ilew1=n/k+bool(n%k!=0);
    int dodac=ilew1*k-n;
    int akt=0;
    cout<<k<<" "<<ilew1<<endl;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<ilew1;j++)
        {
            if(j!=ilew1-1)
           {
                cout<<s[akt]; akt++;
           }
           else
           {
               if(dodac>0)
               {
                   cout<<"*"; dodac--;

               }
               else
                   {
                       cout<<s[akt]; akt++;
                   }
           }
        }

        cout<<endl;
    }
    return 0;
}