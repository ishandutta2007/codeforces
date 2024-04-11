#include <bits/stdc++.h>
using namespace std;
const int MX=200200,md=998244353;
int t,it,n,m,i,j,r,a[MX],b[MX],was[MX],where[MX];
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++)  {
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      where[a[i]]=i;
    }
    for (i=0; i<m; i++) {
      scanf("%d",&b[i]);
      was[where[b[i]]]=it;
    }
    r=1;
    for (i=0; i<m; i++) {
      j=where[b[i]];
      r=(r*(int(j>0 && was[j-1]!=it)+int(j+1<n && was[j+1]!=it)))%md;
      was[j]=0;
    }
    printf("%d\n",r);
  }
  return 0;
}