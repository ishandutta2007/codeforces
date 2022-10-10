#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int n,md,smd,phi,x,y,z,i,s[MX];
vector<int> g[MX],e[MX];
map<int,long long> up,dn;
bool u[MX];
long long pw10[MX],opw10[MX],r;
long long pw(long long a, int b) {
  if (b==0) return 1LL%md;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
void dfs(int i, int p) {
  s[i]=1;
  for (int k : g[i]) if (k!=p && !u[k]) {
    dfs(k,i);
    s[i]+=s[k];
  }
}
int cfs(int i, int p, int n) {
  for (int k : g[i]) if (k!=p && !u[k] && s[k]>n/2) return cfs(k,i,n);
  return i;
}
void solve(int i, int p, int d, int dnc, int upc) {
  ++up[upc%md];
  //printf("  solve %d %d %d (%d %d) %d %d (=%d*%d)\n",i,p,d,upc,dnc,upc%md,(((md-dnc)%md)*opw10[d])%md,(md-dnc)%md,int(opw10[d]));
  ++dn[(((md-dnc)%md)*opw10[d])%md];
  dnc=(dnc*10LL)%md;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (k==p || u[k]) continue;
    solve(k,i,d+1,(dnc+e[i][j])%md,(upc+pw10[d]*e[i][j])%md);
  }
}
void solvecd(int i) {
//printf("solvecd %d\n",i);
  dfs(i,-1);
  u[i]=true;
  map<int,long long> curup,curdn;
  curup[0]=1;
  curdn[0]=1;
  for (int j=0; j<g[i].size(); j++) {
    int k=g[i][j];
    if (u[k]) continue;
    //printf("%d->%d:\n",i,k);
    up.clear();
    dn.clear();
    solve(k,i,1,e[i][j]%md,e[i][j]%md);
    for (auto it : up) {
      //printf("up: %d x%d\n",it.first,it.second);
      auto ft=curdn.find(it.first);
      if (ft!=curdn.end()) r+=1LL*ft->second*it.second;
      //printf("  r=%I64d\n",r);
    }
    for (auto it : dn) {
      auto ft=curup.find(it.first);
      //printf("dn: %d x%d\n",it.first,it.second);
      if (ft!=curup.end()) r+=1LL*ft->second*it.second;
      //printf("  r=%I64d\n",r);
    }
    for (auto it : up) curup[it.first]+=it.second;
    for (auto it : dn) curdn[it.first]+=it.second;
    //printf("r=%I64d\n",r);
  }
  for (int k : g[i]) if (!u[k]) solvecd(cfs(k,i,s[k]));
}
int main() {
  scanf("%d%d",&n,&md);
  if (md==1) { printf("%I64d\n",(n*(n-1LL))); return 0; }
  smd=md; phi=md;
  for (i=2; i*i<=smd; i++) if (smd%i==0) {
    phi-=phi/i;
    for (smd/=i; smd%i==0; smd/=i);
  }
  if (smd>1) phi-=phi/smd;
  for (opw10[0]=pw10[0]=i=1; i<=n; i++) {
    pw10[i]=(pw10[i-1]*10LL)%md;
    opw10[i]=pw(pw10[i],phi-1);
    //if (i<5) printf("%d: %d %d = %d\n",i,int(pw10[i]),int(opw10[i]),int((opw10[i]*pw10[i])%md));
  }
  for (i=1; i<n; i++) {
    scanf("%d%d%d",&x,&y,&z);
    g[x].push_back(y); e[x].push_back(z);
    g[y].push_back(x); e[y].push_back(z);
  }
  dfs(0,-1);
  solvecd(cfs(0,-1,n));
  printf("%I64d\n",r);
  return 0;
}