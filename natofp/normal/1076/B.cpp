#include <iostream>
#include <bits/stdc++.h>


using namespace std;



int main()
{
   long long int n;
   cin>>n;
   long long int ans=0;

   for(long long int i=2;i*i<=n;i++)
   {
       if(n%i==0)
       {
           if(i==2) {cout<<n/2; return 0;}
           else
           {
               n-=i;
               cout<<1+n/2; return 0;
           }
       }
   }
   cout<<1;

    return 0;
}