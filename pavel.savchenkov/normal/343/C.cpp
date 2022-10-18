#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>

#define LL long long
#define S system("pause")

using namespace std;

LL g[100010],c[100010],gLast,cLast;
LL n,m,i,k,last,l,r;
int l1, r1, m1;

bool F(LL P)
 {
  last=1;
  for (i=1;i<=cLast;i++)
   {
    if (last == gLast) break;
    l1=last;
    r1=gLast-1;
    while (l1+1 < r1)
     {
      m1=(l1+r1)/2;
      if (((abs(c[i]-g[last])+abs(g[m1]-g[last])) <= P) || 
          ((abs(c[i]-g[m1])+abs(g[m1]-g[last])) <= P)) l1=m1; else r1=m1-1;
     }
    if (((abs(c[i]-g[last])+abs(g[r1]-g[last])) <= P) || 
       ((abs(c[i]-g[r1])+abs(g[r1]-g[last])) <= P)) last=r1+1; else
    if (((abs(c[i]-g[last])+abs(g[l1]-g[last])) <= P) || 
       ((abs(c[i]-g[l1])+abs(g[l1]-g[last])) <= P)) last=l1+1;
   }
  if (last == gLast) return true; else return false;
 }


main()
 {
  
  cin>>n>>m;
  
  for (i=1;i<=n;i++)
   scanf("%I64d",&k),cLast++,c[cLast]=k;
  
  for (i=1;i<=m;i++)
   scanf("%I64d",&k),gLast++,g[gLast]=k;
  gLast++;
  
  l=0;
  r=20000000000LL;
  while (l+1 < r)
   {
    m=(l+r)/2;
    if (F(m)) r=m; else l=m+1;
   }
  if (F(l)) cout<<l<<endl; else cout<<r<<endl;
    
 }