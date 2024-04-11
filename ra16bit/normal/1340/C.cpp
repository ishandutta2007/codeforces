#include <bits/stdc++.h>
using namespace std;
const long long inf=1000000000000000LL;
const int MID=11000100;
int w,g,r,n,i,j,k,x,cur,fi,fr,a[10100],q[4*MID],d[MID];
long long res=inf;
int main() {
  scanf("%d%d",&w,&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  scanf("%d%d",&g,&r);
  sort(a,a+n);
  q[fi=2*MID]=0;
  fr=fi+1;
  d[0]=1;
  while (fi<fr) {
    x=q[fi++];
    i=(x>>10);
    j=(x&1023);
    cur=d[x];
    if (i==n-1) {
      if (j) {
        res=min(res,(cur-1LL)*(g+r)+j);
      } else {
        res=min(res,(cur-1LL)*g+(cur-2LL)*r);
      }
      continue;
    }
    if (i+1<n) {
      k=j+a[i+1]-a[i];
      if (k<g) {
        x=((i+1)<<10)+k;
        if (d[x]==0) {
          d[x]=cur;
          q[--fi]=x;
        }
      } else if (k==g) {
        x=((i+1)<<10);
        if (d[x]==0) {
          d[x]=cur+1;
          q[fr++]=x;
        }
      }
    }
    if (i>0) {
      k=j+a[i]-a[i-1];
      if (k<g) {
        x=((i-1)<<10)+k;
        if (d[x]==0) {
          d[x]=cur;
          q[--fi]=x;
        }
      } else if (k==g) {
        x=((i-1)<<10);
        if (d[x]==0) {
          d[x]=cur+1;
          q[fr++]=x;
        }
      }
    }
  }
  if (res==inf) puts("-1"); else printf("%I64d\n",res);
  return 0;
}