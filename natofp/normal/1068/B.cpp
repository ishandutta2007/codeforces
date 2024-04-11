#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   long long int n;
   cin>>n;
   int ans=0;
   long long int i;
   for(i=1;i*i<=n;i++)
   {
       if(n%i==0) ans+=2;
   }
   i--;
   if(i*i==n) ans--;
   cout<<ans;
    return 0;
}