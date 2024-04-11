#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,k,e,sum,x[1010],y[1010],b[2020],l[1010],r=2000000000;
bool cmp(int i, int j) {
  return y[i]-x[i]<y[j]-x[j];
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x[i],&y[i]);
    b[m++]=x[i];
    b[m++]=y[i];
  }
  sort(b,b+m);
  reverse(b,b+m);
  for (i=0; i<m; i++) {
    for (sum=e=k=j=0; j<n; j++) if (y[j]>b[i]) {
      if (x[j]>b[i]) break;
      sum+=y[j]; k++;
    } else if (x[j]<=b[i]) l[e++]=j; else sum+=x[j];
    if (j<n || k*2>n) continue;
    sort(l,l+e,cmp);
    for (j=0; j<e; j++) if ((k+1)*2<=n && y[l[j]]<x[l[j]]) {
      sum+=y[l[j]]; k++;
    } else sum+=x[l[j]];
    r=min(r,b[i]*sum);
  }
  printf("%d\n",r);
  return 0;
}