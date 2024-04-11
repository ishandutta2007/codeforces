#include <bits/stdc++.h>
using namespace std;
const int inf=1000000;
int n,i,l,r,nxt,hl,hr,a[100100];
int ask(int x) {
  if (a[x]!=0) return a[x];
  printf("? %d\n",x);
  fflush(stdout);
  int r;
  scanf("%d",&r);
  return r;
}
int main() {
  scanf("%d",&n);
  l=0; r=n+1;
  a[0]=a[n+1]=inf;
  while (l+6<r) {
    nxt=(l+r)/2;
    hl=(l+l+r)/3;
    hr=(l+r+r)/3;
    a[nxt]=ask(nxt);
    a[hl]=ask(hl);
    a[hr]=ask(hr);
    if (a[hl]>a[nxt] && a[hr]>a[nxt]) {
      l=hl; r=hr; continue;
    }
    if (a[nxt]>a[hl]) {
      r=nxt; nxt=hl;
    } else {
      l=nxt; nxt=hr;
    }
  }
  for (i=max(l,1); i<=min(n,r); i++) {
    a[i-1]=ask(i-1);
    a[i]=ask(i);
    a[i+1]=ask(i+1);
    if (a[i]<a[i-1] && a[i]<a[i+1]) {
      printf("! %d\n",i);
      return 0;
    }
  }
  return 0;
}