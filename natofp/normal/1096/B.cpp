#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n; cin>>n;
   string s; cin>>s;
   long long int ans=0;
   int i=1;
   while(s[i]==s[i-1]) i++;
   int l,r;
   l=i-1;
   i=n-2;
   while(s[i]==s[i+1]) i--;
   r=i+1;
   bool czy=false;
   if(s[0]==s[n-1]) czy=true;
   for(int i=0;i<n;i++)
   {
       if(i==0)
       {
           ans+=n-r+1;
       }
       else if(i<=l+1)
       {
           if(czy)
           {
               ans+=n-r+1;
           }
           else ans++;


       }
       else continue;

   }
   cout<<ans%998244353;
    return 0;
}