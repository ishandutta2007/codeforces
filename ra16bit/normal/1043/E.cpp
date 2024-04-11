#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,x[300300],y[300300],k[300300];
long long ii,cur,r[300300];
bool cmp(int i, int j) {
  return x[i]-y[i]>x[j]-y[j];
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x[i],&y[i]);
    k[i]=i;
  }
  sort(k,k+n,cmp);
  for (ii=0; ii<n; ii++) {
    i=k[ii];
    r[i]=x[i]*ii+y[i]*(n-1-ii)+cur;
    cur+=y[i];
  }
  cur=0;
  for (ii=n-1; ii>=0; ii--) {
    i=k[ii];
    r[i]+=cur;
    cur+=x[i];
  }
  //for (i=0; i<n; i++) printf("%I64d ",r[i]);
  while (m--) {
    scanf("%d%d",&i,&j);
    --i; --j;
    if (x[i]-y[i]<x[j]-y[j]) {
      r[i]-=x[i]+y[j];
      r[j]-=x[i]+y[j];
    } else {
      r[i]-=x[j]+y[i];
      r[j]-=x[j]+y[i];
    }
    //for (i=0; i<n; i++) printf("%I64d ",r[i]); puts("");
  }
  for (i=0; i<n; i++) printf("%I64d ",r[i]);
  return 0;
}