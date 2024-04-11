#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int n,i,x,cur,r,a[MX],w[MX];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) { scanf("%d",&x); w[x]=n-i; }
  cur=n+1;
  for (i=0; i<n; i++) {
    if (cur<w[a[i]]) ++r;
    cur=min(cur,w[a[i]]);
  }
  printf("%d\n",r);
  return 0;
}