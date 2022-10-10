#include <bits/stdc++.h>
using namespace std;
const int MX=400100;
int t,n,i,a[MX],w[MX],mnl[MX],mxl[MX],mnr[MX],mxr[MX];
int goleft(int i, int x) {
  if (i==1) return 0;
  if (x==0) return goleft(w[mxl[i]],1)+1;
  return goleft(w[mnl[i]],0)+1;
}
int goright(int i, int x) {
  if (i==n) return 0;
  if (x==0) return goright(w[mxr[i]],1)+1;
  return goright(w[mnr[i]],0)+1;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    mnl[0]=mnr[n+1]=n+1;
    mxl[0]=mxr[n+1]=0;
    for (i=1; i<=n; i++) {
      scanf("%d",&a[i]);
      mnl[i]=min(mnl[i-1],a[i]);
      mxl[i]=max(mxl[i-1],a[i]);
      w[a[i]]=i;
    }
    for (i=n; i>0; i--) {
      mnr[i]=min(mnr[i+1],a[i]);
      mxr[i]=max(mxr[i+1],a[i]);
    }
    if (n==1) { puts("0"); continue; }
    if (w[1]<w[n]) {
      printf("%d\n",goleft(w[1],0)+goright(w[n],1)+1);
    } else {
      printf("%d\n",goleft(w[n],1)+goright(w[1],0)+1);
    }
  }
  return 0;
}