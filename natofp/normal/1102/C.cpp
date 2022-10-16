#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,x,y;
   cin>>n>>x>>y;
   if(x>y) {cout<<n; return 0;}
   int * a=new int[n];
   for(int i=0;i<n;i++) cin>>a[i];
   int ile=0;
   for(int i=0;i<n;i++)
   {
       if(a[i]<=x) ile++;
   }
   cout<<(ile+1)/2;
    
    return 0;
}