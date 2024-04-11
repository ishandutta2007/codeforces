#include <bits/stdc++.h>
using namespace std;
const int MX=111;
int t,n,r,u,v,i,a[MX];
bool good,ok;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d",&n,&u,&v);
    good=ok=false;
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      if (i>0 && a[i]!=a[i-1]) {
        if (a[i]==a[i-1]+1 || a[i]==a[i-1]-1) ok=true; else good=true;
      }
    }
    if (good) puts("0"); else {
      if (ok) r=0; else r=v;
      printf("%d\n",r+min(u,v));
    }
  }
  return 0;
}