#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int n,m,i,j,v,pv,cur,res,x[MX],z[MX],k[MX],o[MX],st[MX],a[MX],l[MX],r[MX];
pair<int,int> e[MX];
bool cmp(int i, int j) { return e[i]<e[j]; }
int findmax(int le, int ri) {
  if (le>ri) return 0;
  int res=max(a[le],a[ri]),i,nx;
  for (i=le; (nx=(i<<1)-(i&(i-1)))<=ri; i=nx) res=max(res,r[i]);
  res=max(res,a[i]);
  for (i=ri; (nx=(i&(i-1)))>=le; i=nx) res=max(res,l[i]);
  res=max(res,a[i]);
  return res;
}
void modify(int x, int v) {
  if (v<=a[x]) return;
  a[x]=v;
  for (int i=x; i<=m; i=(i<<1)-(i&(i-1))) l[i]=max(l[i],v);
  for (int i=x; i>0; i&=i-1) r[i]=max(r[i],v);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&x[i],&e[i].first,&e[i].second);
    k[i]=i;
  }
  sort(k,k+m,cmp);
  for (pv=i=0; i<m; i++) {
    o[k[i]]=i;
    cur=e[k[i]].first;
    z[i]=e[k[i]].second;
    for (j=pv+1; j<=cur; j++) st[j]=i;
    pv=cur;
  }
  for (j=pv+1; j<=n+1; j++) st[j]=m;
  for (i=0; i<m; i++) {
    j=lower_bound(z+st[x[i]],z+st[x[i]+1],e[i].second)-z;
    v=findmax(st[x[i]]+1,j);
    modify(o[i]+1,v+1);
    res=max(res,v+1);
  }
  printf("%d\n",res);
  return 0;
}