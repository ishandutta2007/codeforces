#include <bits/stdc++.h>
using namespace std;
const int MX=150150,LIM=400,md=998244353;
int n,bc,q,i,x,y,z,zz,t,fi[MX],lst[MX],b[MX],s[MX];
long long dv,cur,a[MX],cnt[MX];
vector<int> g[MX];
bool big[MX];
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
void dfs(int i, int p) {
  fi[i]=++t;
  cnt[i]=1;
  if (p!=0) {
    int j=0;
    for (; j<g[i].size(); j++) if (g[i][j]==p) break;
    swap(g[i][0],g[i][j]);
  }
  for (int j=int(p!=0); j<g[i].size(); j++) {
    int k=g[i][j];
    dfs(k,i);
    cnt[i]+=cnt[k];
  }
  lst[i]=t;
  //printf("%d [%d %d]\n",i,fi[i],lst[i]);
}
void modify(int l, int r, int v) {
  if (l>r) return;
  //printf("modify %d..%d += %d\n",l,r,v);
  for (; l<=n; l=(l<<1)-(l&(l-1))) s[l]=(s[l]+v)%md;
  for (++r; r<=n; r=(r<<1)-(r&(r-1))) s[r]=(s[r]+md-v)%md;
}
long long fsum(int x) {
  long long r=0;
  //printf("sum %d = ",x);
  for (; x>0; x&=x-1) r=(r+s[x])%md;
  //printf("%d\n",int(r));
  return r;
}
int main() {
  scanf("%d%d",&n,&q);
  dv=pw(n,md-2);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (i=1; i<=n; i++) if (g[i].size()>=LIM) {
    big[i]=true;
    b[bc++]=i;
    //printf("%d is big\n",i);
  }
  dfs(1,0);
  while (q--) {
    scanf("%d%d",&y,&x);
    if (y==1) {
      scanf("%d",&y);
      a[x]=(a[x]+y)%md;
      if (!big[x]) {
        for (i=int(x!=1); i<g[x].size(); i++) {
          z=g[x][i];
          modify(fi[z],lst[z],(y*(n-cnt[z]))%md);
        }
        if (x!=1) {
          cur=(y*cnt[x])%md;
          modify(1,fi[x]-1,cur);
          modify(lst[x]+1,n,cur);
        }
      }
    } else {
      cur=fsum(fi[x]);
      cur=(cur+a[x]*n)%md;
      for (zz=0; zz<bc; zz++) {
        z=b[zz];
        if (z==x || a[z]==0) continue;
        if (fi[x]<fi[z] || lst[x]>lst[z]) {
          cur=(cur+a[z]*cnt[z])%md;
        } else {
          int le=int(z!=1),ri=int(g[z].size())-1;
          while (le<ri) {
            int h=(le+ri)/2;
            if (lst[x]<=lst[g[z][h]]) ri=h; else le=h+1;
          }
          cur=(cur+a[z]*(n-cnt[g[z][ri]]))%md;
        }
      }
      printf("%I64d\n",(cur*dv)%md);
    }
  }
  return 0;
}