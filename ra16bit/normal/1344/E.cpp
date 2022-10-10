#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=200200;
int T,n,m,i,x,y,z,pos,cnt,le,ri,h,fi[MX],lst[MX],s[MX],t[MX],ch[MX],a[18][MX],npw[MX],L[MX],R[MX],A[MX];
priority_queue<ll,vector<ll>,greater<ll>> q;
pair<ll,ll> seg[MX*44];
vector<int> g[MX],f[MX];
ll d[MX],j;
void dfs(int i, ll dep) {
  a[0][++T]=i;
  fi[i]=T; d[i]=dep;
  for (int j=0; j<g[i].size(); j++) {
   dfs(g[i][j],dep+f[i][j]);
   a[0][++T]=i;
  }
  lst[i]=T;
}
int lca(int i, int j) {
  if (i>j) return lca(j,i);
  int len=npw[j-i+1];
  int le=a[len][i];
  int ri=a[len][j-(1<<len)+1];
  if (d[le]<=d[ri]) return le;
  return ri;
}
int fndmax(int l, int r) {
  int res=max(A[l],A[r]),x,nxt;
  for (x=l; ; x=nxt) {
    nxt=(x<<1)-(x&(x-1));
    if (nxt>r) break;
    res=max(res,L[x]);
  }
  res=max(res,A[x]);
  for (x=r; ; x=nxt) {
    nxt=(x&(x-1));
    if (nxt<l) break;
    res=max(res,R[x]);
  }
  res=max(res,A[x]);
  return res;
}
void mdf(int i, int v) {
  A[i]=max(A[i],v);
  for (int x=i; x<=T; x=(x<<1)-(x&(x-1))) R[x]=max(R[x],v);
  for (int x=i; x>0; x&=x-1) L[x]=max(L[x],v);
}
void printans(int i) {
  for (cnt=x=0; x<i; x++) if (seg[x].second<q.top()) ++cnt;
  printf("%I64d %d\n",q.top(),cnt);
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<n; i++) {
    scanf("%d%d%d",&x,&y,&z);
    g[x].push_back(y);
    f[x].push_back(z);
  }
  for (i=1; i<=n; i++) ch[i]=int(g[i].size())-1;
  dfs(1,0);
  for (x=1; x<18; x++) for (i=1; i<=T; i++) {
    a[x][i]=a[x-1][i];
    y=i+(1<<(x-1));
    if (y<=T && d[a[x-1][y]]<d[a[x][i]]) a[x][i]=a[x-1][y];
  }
  for (x=1, y=-1, i=1; i<=T; i++) {
    if (i==x) { x*=2; y++; }
    npw[i]=y;
  }
  for (i=1; i<=m; i++) {
    scanf("%d%d",&s[i],&t[i]);
    pos=fi[s[i]];
    for (j=1; j!=s[i]; j=y) {
      z=fndmax(fi[j]+1,lst[j]);
      if (z!=0) {
        j=lca(fi[s[z]],pos);
        if (j==s[i]) break;
      }
      y=g[j][ch[j]];
      z=fndmax(fi[y],lst[y]);
      if (pos<fi[y] || pos>lst[y]) {
        le=0;
        ri=int(g[j].size())-1;
        while (le<ri) {
          h=(le+ri)/2;
          if (lst[g[j][h]]<pos) le=h+1; else ri=h;
        }
        seg[cnt++]={z?t[z]+d[j]+1:1,t[i]+d[j]};
        ch[j]=ri;
        y=g[j][ri];
      }
    }
    mdf(pos,i);
  }
  sort(seg,seg+cnt);
  for (j=i=0; i<cnt; i++) {
    for (; j<seg[i].first && !q.empty(); j++) {
      if (q.top()<j) { printans(i); return 0; }
      q.pop();
    }
    j=seg[i].first;
    q.push(seg[i].second);
  }
  while (!q.empty()) {
    if (q.top()<j) { printans(cnt); return 0; }
    q.pop(); j++;
  }
  printf("-1 %d\n",cnt);
  return 0;
}