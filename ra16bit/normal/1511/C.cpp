#include <bits/stdc++.h>
using namespace std;
const int MX=654321;
int n,m,q,i,x,a[MX],s[MX],lst[55];
void add(int i, int v) {
  for (; i<=m; i=(i<<1)-(i&(i-1))) s[i]+=v;
}
int sum(int i) {
  int r=0;
  for (; i>0; i&=i-1) r+=s[i];
  return r;
}
int main() {
  scanf("%d%d",&n,&q);
  m=n+q;
  for (i=n; i>=1; i--) scanf("%d",&a[i]);
  for (i=1; i<=n; i++) {
    lst[a[i]]=i;
    add(i,1);
  }
  for (i=1; i<=q; i++) {
    scanf("%d",&x);
    printf("%d ",n+1-sum(lst[x]));
    add(lst[x],-1);
    lst[x]=n+i;
    add(n+i,1);
  }
  return 0;
}