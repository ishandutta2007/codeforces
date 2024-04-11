#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int t; cin>>t;
   while(t--)
   {
       bool czy=false;
       int a; cin >>a;
       for(int i=3;i<=360;i++)
       {
           for(int j=1;j<=i-2;j++)
           {
               if(a*i==j*180) {cout<<i<<endl; czy=true; i=12332; break;}
           }
       }
       if(czy==false) cout<<-1<<endl;
   }
    return 0;
}