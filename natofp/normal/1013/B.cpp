#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
   int n,x;
   cin>>n>>x;
   int * a;
   a=new int[n];
   for(int i=0;i<n;i++) cin>>a[i];
   sort(a,a+n);
   for(int i=1;i<n;i++)
   {
       if(a[i]==a[i-1]) {cout<<"0"; return 0;}
   }
   int * tab;
   int k=a[n-1];
   tab=new int[k+1];
   for(int i=0;i<=k;i++) tab[i]=0;
   for(int i=0;i<n;i++)
   {
       tab[a[i]]++;
   }
   for(int i=0;i<n;i++)
   {
       tab[a[i]]--;
       if(tab[x&a[i]]>0) {cout<<"1"; return 0;}
       tab[a[i]]++;
   }
   for(int i=0;i<n;i++)
   {
       a[i]=(a[i]&x);
   }
   sort(a,a+n);
   for(int i=1;i<n;i++)
   {
       if(a[i]==a[i-1]) {cout<<"2"; return 0;}
   }
   cout<<"-1";

    return 0;
}