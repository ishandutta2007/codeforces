#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct song
{
    int a;
    int b;
};

bool por(song j,song d)
{
    return (j.a-j.b)<(d.a-d.b);
}

int main()
{
   int n,m;
   cin>>n>>m;
   song * tab;
   tab=new song[n];
   for(int i=0;i<n;i++)
   {
       cin>>tab[i].a>>tab[i].b;
   }
   sort(tab,tab+n,por);
   long long sum=0;
   for(int i=0;i<n;i++)
   {
       sum+=tab[i].b;
   }
   if(sum>m) {cout<<"-1"; return 0;}
   int w=n;
   for(int i=0;i<n;i++)
   {
       if(sum+tab[i].a-tab[i].b<=m) {sum+=tab[i].a; sum-=tab[i].b; w--;}
       else break;
   }
   cout<<w;
    return 0;
}