#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int main()
{
   long long int n,k,s;
   cin>>n>>k>>s;
   if((n-1)*k<s || s<k) {cout<<"NO"; return 0;}
   cout<<"YES"<<endl;


       long long d=s/k;
       long long e=s%k;

   long long ini=1;
   for(int i=0;i<e;i++)
   {
       if(i%2==0) ini+=(d+1);
       else ini-=(d+1);
       cout<<ini<<" ";
   }
   for(int i=e;i<k;i++)
   {
       if((ini+d)<=n) {ini+=d;}
       else ini-=d;
       cout<<ini<<" ";
   }
    return 0;
}