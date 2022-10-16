#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct uczen
{
    int a;
    int b;
    int idx;
};

bool por(uczen a,uczen b)
{
    return (a.a+a.b)<(b.a+b.b);
}

bool por2(uczen a,uczen b)
{
    return a.idx<b.idx;
}

int main()
{
   int n;
   cin>>n;
   uczen * a;
   a=new uczen[n];
   for(int i=0;i<n;i++)
   {
       cin>>a[i].a;
   }
   for(int i=0;i<n;i++)
   {
       cin>>a[i].b;
   }
   for(int i=0;i<n;i++) a[i].idx=i;
   sort(a,a+n,por);
   int * ans;
   int akt=n;
   int pop=-1;
   int last=1;
   ans=new int[n];
   for(int i=0;i<n;i++)
   {
       int t=a[i].idx;

       if(i!=0)
       {
           if(a[i].a+a[i].b!=pop) {akt-=last; last=1; pop=a[i].a+a[i].b;}
           else
           {
               last++;
           }
       }
       ans[t]=akt;
       pop=a[i].a+a[i].b;



   }
   sort(a,a+n,por2);
   bool xd=true;
   for(int i=0;i<n;i++)
   {
        int lewo=0; int prawo=0;
       for(int j=i-1;j>=0;j--)
       {
           if(ans[j]>ans[i]) lewo++;
       }
       for(int j=i+1;j<n;j++)
       {
           if(ans[j]>ans[i]) prawo++;
       }
       if(lewo!=a[i].a || prawo!=a[i].b) xd=false;
   }
   if(xd==false) cout<<"NO";
   else
   {
       cout<<"YES"<<endl;
       for(int i=0;i<n;i++) cout<<ans[i]<<" ";
   }
    return 0;
}