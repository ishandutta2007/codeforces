#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n,k;
   cin>>n>>k;
   int * tab;
   tab=new int[n];
   for(int i=0;i<n;i++)
    cin>>tab[i];

   sort(tab,tab+n);
   if(k==0 && tab[0]>=2) cout<<"1";
    else if(k==0 && tab[0]<2) cout<<"-1";
   else if (k==n)
   {
        cout<<"1000000000";

   }
   else  if( n>=2 && tab[k-1]!=tab[k])
   {
       cout<<tab[k-1];
   }
   else cout<<"-1";
    return 0;
}