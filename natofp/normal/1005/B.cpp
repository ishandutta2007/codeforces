#include <iostream>
#include <bits/stdc++.h>2
using namespace std;

int main()
{
   string a,b;
   cin>>a>>b;
   reverse(a.begin(),a.end());
   reverse(b.begin(),b.end());
   int x=min(a.length(),b.length());
   int i=0;
   int k=0;
   while(i<x && a[i]==b[i])
   {
       k++;
       i++;
   }
   cout<<a.length()+b.length()-2*k;


    return 0;
}