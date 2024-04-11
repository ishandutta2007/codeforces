#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n,m;
   cin>>n>>m;
   string a,b;
   int x=n;
   while(n>=0)
   {
       a+='5';
       n-=5;
   }
   while(x>=0)
   {
       b+='4';
       x-=4;
   }
   while(a.length()>b.length()) b+='4';
   while(b.length()>a.length()) a+='5';
   a+='5';
   b+='5';
   cout<<a<<endl<<b;
    return 0;
}