#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
 int n; cin>>n;
 int mniejszemax=0,wiekszemax=0;
 while(n--)
 {
     char x; int a,b; cin>>x>>a>>b;
     if(x=='+')
     {
         if(a>b) swap(a,b);
         mniejszemax=max(mniejszemax,a);
         wiekszemax=max(wiekszemax,b);
     }
     else
     {
            if(a>b) swap(a,b);
            if(a>=mniejszemax && b>=wiekszemax) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
     }
 }
    return 0;
}