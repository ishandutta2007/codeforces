#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   int w=0;
   int * a;
   a=new int[2*n];
   for(int i=0;i<2*n;i++)
    cin>>a[i];
   for (int i=0;i<n;i++)
   {
       int x=2*i+1;
       while(a[x]!=a[2*i]) x++;
       for(int j=x;j>2*i+1;j--)
       {
           w++;
           int p=a[j];
            a[j]=a[j-1];
            a[j-1]=p;
       }
   }
   cout<<w;
    return 0;
}