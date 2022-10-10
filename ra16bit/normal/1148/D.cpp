#include <bits/stdc++.h>
using namespace std;
int n,nc,nd,i,a[300300],b[300300],c[300300],d[300300];
bool cmpc(int i, int j) { return a[i]>a[j]; }
bool cmpd(int i, int j) { return a[i]<a[j]; }
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&a[i],&b[i]);
    if (a[i]<b[i]) c[nc++]=i; else d[nd++]=i;
  }
  if (nc>nd) {
    sort(c,c+nc,cmpc);
    printf("%d\n",nc);
    for (i=0; i<nc; i++) printf("%d ",c[i]+1);
  } else {
    sort(d,d+nd,cmpd);
    printf("%d\n",nd);
    for (i=0; i<nd; i++) printf("%d ",d[i]+1);
  }
  return 0;
}