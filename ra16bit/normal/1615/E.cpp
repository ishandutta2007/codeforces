#include <bits/stdc++.h>
using namespace std;
const int MX=270270;
struct Node {
  int mx,add;
} b[2*MX];
int n,m,x,y,cnt,num,o[MX],d[MX],fi[MX],lst[MX],prv[MX];
long long i,res,rst;
vector<int> g[MX];
bool u[MX];
void dfs(int i, int p, int dep) {
  bool was=false;
  prv[i]=p;
  fi[i]=++num;
  o[num]=i;
  d[i]=dep;
  for (int j: g[i]) if (j!=p) {
    was=true;
    dfs(j,i,dep+1);
  }
  if (!was) ++cnt;
  lst[i]=num;
}
void init(int i, int L, int R) {
  b[i].add=0;
  if (L==R) {
    b[i].mx=d[o[R]];
    return;
  }
  int mid=(L+R)/2;
  init(i*2,L,mid);
  init(i*2+1,mid+1,R);
  b[i].mx=max(b[i*2].mx,b[i*2+1].mx);
}
void upd(int i, int L, int R, int le, int ri) {
  if (L==le && R==ri) {
    --b[i].add;
    --b[i].mx;
    return;
  }
  int mid=(L+R)/2;
  if (le<=mid) upd(i*2,L,mid,le,min(mid,ri));
  if (ri>mid) upd(i*2+1,mid+1,R,max(le,mid+1),ri);
  b[i].mx=max(b[i*2].mx,b[i*2+1].mx)+b[i].add;
}
int fndmax(int i, int L, int R) {
  if (L==R) return o[R];
  int mid=(L+R)/2;
  if (b[i*2].mx>=b[i*2+1].mx) return fndmax(i*2,L,mid);
  return fndmax(i*2+1,mid+1,R);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1,0,1);
  if (cnt<=m) {
    for (i=cnt; i<=m; i++) res=max(res,(n-i)*i);
    printf("%lld\n",res);
    return 0;
  }
  init(1,1,num);
  u[0]=true;
  rst=n;
  for (i=0; i<m; i++) {
    x=fndmax(1,1,num);
    for (; !u[x]; x=prv[x]) {
      u[x]=true;
      --rst;
      upd(1,1,num,fi[x],lst[x]);
    }
  }
  res=1000000000;
  res*=res;
  for (i=0; i<=rst; i++) res=min(res,(n-m-i)*(m-i));
  printf("%lld\n",res);
  return 0;
}