#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

   int n,m;
   cin>>n>>m;
   int * a;
   a=new int[n];
   for(int i=0;i<n;i++) cin>>a[i];
   int x;
   for(int i=0;i<n;i++) if(a[i]==m) x=i;
   int * pre;
   pre = new int [n+1];
   pre[0]=0;

   for(int i=1;i<=n;i++)
   {
        if(i==x+1) pre[i]=pre[i-1];
        if(a[i-1]>m) pre[i]=pre[i-1]+1;
        else if(a[i-1]<m) pre[i]=pre[i-1]-1;



   }
   long long int w=0;
   map <int,int> mapa;
   for(int i=x+1;i<=n;i++)
   {
       mapa[pre[i]]++;

   }
   for(int i=0;i<=x;i++)
   {

       w+=mapa[pre[i]];
       w+=mapa[pre[i]+1];
   }
   cout<<w;
    return 0;
}