#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct wartosc
{
    long long val;
    bool typ;
};

bool por(wartosc a,wartosc b)
{
    if(a.val==b.val) return a.typ<b.typ;
    else return a.val<b.val;
}

int main()
{
   int n;
   cin>>n;
   wartosc * a;
   a=new wartosc[2*n+1];
   for(int i=0;i<2*n;i++)
   {
       cin>>a[i].val;
       a[i].typ=i%2;
   }
   a[2*n].val=1000000000000000001;
   sort(a,(a+2*n),por);
   vector<long long int> wyniki(n+1,0);
   int cur=1;
   for(int i=1;i<2*n;i++)
   {
       if(a[i].val!=a[i-1].val) wyniki[cur]+=(a[i].val-a[i-1].val-1);
       if(a[i].typ) cur--;
       else cur++;
   }
   cur=0;
    long long pozycja=-1;
   for(int i=0;i<2*n;i++)
   {
      if(a[i].typ==0)
      {
          cur++;
          if(a[i+1].val!=a[i].val || a[i+1].typ==1) {wyniki[cur]++;  pozycja=a[i].val;}
      }
      else
      {
          if(pozycja!=a[i].val) {wyniki[cur]++; cur--; pozycja=a[i].val;}
          else cur--;
      }


   }
   for(int i=1;i<=n;i++) cout<<wyniki[i]<<" ";
    return 0;
}