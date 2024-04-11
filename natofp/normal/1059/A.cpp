#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
   int n; cin>>n;
   int l,k;
   cin>>l>>k;
   int akt=0;
   int ans=0;
   for(int i=0;i<n;i++)
   {
       int x,t;
       cin>>x>>t;
       ans+=(x-akt)/k;
       akt=x+t;
   }
   ans+=(l-akt)/k;
   cout<<ans;
    return 0;
}