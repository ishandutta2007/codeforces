#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n; cin>>n;
   int * a;
   a=new int[n];
   for(int i=0;i<n;i++) cin>>a[i];
   int b,c,d,e;
   b=0; c=0; d=0; e=0;
   for(int i=0;i<n;i++)
   {
       if(a[i]==1) {b++; d++;}
       else {c++; e++;}
       if(b>c) c=b;
       if(c>d) d=c;
       if(d>e) e=d;
   }
   cout<<e;
    return 0;
}