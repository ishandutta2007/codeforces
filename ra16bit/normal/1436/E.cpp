#include <bits/stdc++.h>
using namespace std;
const int MX=140140,inf=1000000000;
int n,i,cur,a[MX],b[MX*2],prv[MX];
bool was[MX],u[MX];
int findmin(int i, int L, int R, int le, int ri) {
  if (L==le && R==ri) return b[i];
  int h=(L+R)/2,cur=inf;
  if (le<=h) cur=min(cur,findmin(i*2,L,h,le,min(ri,h)));
  if (ri>h) cur=min(cur,findmin(i*2+1,h+1,R,max(h+1,le),ri));
  return cur;
}
void upd(int i, int L, int R, int pos, int v) {
  if (L==R) {
    b[i]=v;
    return;
  }
  int h=(L+R)/2;
  if (pos<=h) upd(i*2,L,h,pos,v); else upd(i*2+1,h+1,R,pos,v);
  b[i]=min(b[i*2],b[i*2+1]);
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    was[a[i]]=true;
  }
  for (i=1; ; i++) if (!was[i]) {
    u[i]=true; break;
  }
  for (i=1; i<=n; i++) {
    cur=a[i];
    if (!u[cur] && prv[cur]<i-1) u[cur]=((cur==1)?true:(findmin(1,1,n,1,cur-1)>prv[cur]));
    upd(1,1,n,cur,i);
    prv[cur]=i;
  }
  if (prv[1]>0 && prv[1]<n) u[1]=true;
  for (i=2; i<=n; i++) if (!u[i] && prv[i]>0 && prv[i]<n && findmin(1,1,n,1,i-1)>prv[i]) u[i]=true;
  for (i=1; ; i++) if (!u[i]) break;
  printf("%d\n",i);
  return 0;
}