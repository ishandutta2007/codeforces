#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
   cin>>n;
   int suma=0;
   int naj=0;
   for(int i=0;i<n;i++)
   {
       int x; cin>>x;
       suma+=x;
       naj=max(naj,x);

   }
   int k=naj;
   while(true)
   {
       if(k*n>2*suma) {cout<<k<<endl; return 0;}
       k++;
   }
    return 0;
}