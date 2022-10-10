#include <bits/stdc++.h>
using namespace std;
const int MX=5005*17,MSK=(1<<15)+5;
int n,i,j,x,cur,st[17],a[MX],b[MX],g[MSK],ra[17],rb[17],v[MSK][22],w[MX],wh[MX];
map<long long,int> m;
long long c[17],s;
bool u[MX],was[MX],f[MSK];
void dfs(int i, int d) {
  w[d]=i;  u[i]=true;
  wh[i]=d; was[i]=true;
  long long cur=s-c[b[i]]+a[i];
  if (m.count(cur)==0) {
    was[i]=false;
    return;
  }
  int e=m[cur];
  if (was[e]) {
    int j=wh[e],mask=0;
    for (; j<=d; j++) if (((mask>>b[w[j]])&1)==0) mask|=(1<<b[w[j]]); else break;
    if (j>=d) {
      v[mask][0]=d-wh[e]+1;
      for (j=0; j<v[mask][0]; j++) v[mask][j+1]=w[wh[e]+j];
    }
  } else if (!u[e]) dfs(e,d+1);
  was[i]=false;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x);
    st[i+1]=st[i]+x;
    for (j=st[i]; j<st[i+1]; j++) {
      scanf("%d",&a[j]);
      b[j]=i;
      m[a[j]]=j;
      c[i]+=a[j];
      s+=a[j];
    }
  }
  if (s%n!=0) { puts("No"); return 0; }
  s/=n;
  for (i=0; i<st[n]; i++) if (!u[i]) dfs(i,0);
  f[0]=true;
  for (i=1; i<(1<<n); i++) for (j=i; j>0; j=(i&(j-1))) if (v[j][0]>0 && f[i^j]) {
    f[i]=true;
    g[i]=j;
    break;
  }
  i=(1<<n)-1;
  if (f[i]) {
    puts("Yes");
    for (; i>0; i^=g[i]) {
      cur=g[i];
      ra[b[v[cur][1]]]=v[cur][1];
      rb[b[v[cur][1]]]=b[v[cur][v[cur][0]]];
      for (j=2; j<=v[cur][0]; j++) {
        ra[b[v[cur][j]]]=v[cur][j];
        rb[b[v[cur][j]]]=b[v[cur][j-1]];
      }
    }
    for (i=0; i<n; i++) printf("%d %d\n",a[ra[i]],rb[i]+1);
  } else puts("No");
  return 0;
}