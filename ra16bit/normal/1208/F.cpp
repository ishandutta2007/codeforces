#include <bits/stdc++.h>
using namespace std;
const int B=21,MASK=(1<<B)-1,MX=1000100;
int n,i,j,k,cur,r,a[MX],mx1[MASK+4],mx2[MASK+4];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=n; i>=1; i--) if (mx1[a[i]]==0) mx1[a[i]]=i;
    else if (mx2[a[i]]==0) mx2[a[i]]=i;
  for (i=MASK; i>0; i--) if (mx1[i]>0) for (j=0; j<B; j++) {
    k=i^(1<<j);
    if (k>=i) continue;
    if (mx2[i]>0) {
      if (mx2[i]>mx1[k]) {
        mx2[k]=mx1[k]; mx1[k]=mx2[i];
      } else if (mx2[i]!=mx1[k] && mx2[i]>mx2[k]) mx2[k]=mx2[i];
    }
    if (mx1[i]>mx1[k]) {
      mx2[k]=mx1[k]; mx1[k]=mx1[i];
    } else if (mx1[i]!=mx1[k] && mx1[i]>mx2[k]) mx2[k]=mx1[i];
  }
  for (i=n-2; i>=1; i--) {
    k=MASK^a[i]; cur=0;
    for (j=B-1; j>=0; j--) if ((k>>j)&1) {
      cur^=(1<<j);
      if (mx2[cur]<=i) cur^=(1<<j);
    }
    r=max(r,a[i]|cur);
  }
  printf("%d\n",r);
  return 0;
}