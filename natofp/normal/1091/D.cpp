#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
   long long int n; cin>>n;
   if(n==1) {cout<<1; return 0;}
   long long int mod=998244353;
   long long int ans=n;
   for(long long int i=1;i<=n;i++)
   {
       ans*=i;
       ans%=mod;
   }
   long long int ile=n;
   long long int akt=n;
   for(long long int i=n-1;i>=2;i--)
   {
       akt*=i;
       akt%=mod;
       ile+=akt;
       ile%=mod;
   }
   ans-=ile;
   if(ans<0) ans+=mod;
   cout<<ans;

    return 0;
}