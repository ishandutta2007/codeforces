#include <bits/stdc++.h>
using namespace std;
const int MX=202,md=1000000007;

struct Modint {
  long long p,q;
  
  Modint() { p=0; q=1; }
  Modint(long long _p, long long _q) : p(_p), q(_q) {}
  
  Modint& operator+=(const Modint& oth) {
    p=(p*oth.q+q*oth.p)%md;
    q=(q*oth.q)%md;
    return *this;
  }
};  
Modint mul(Modint x, long long p, long long q) {
  x.p=(x.p*p)%md;
  x.q=(x.q*q)%md;
  return x;
}

long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}

int n,i,j,k,x,y,st,cnt[MX],all[MX];
vector<int> g[MX];
Modint dp[MX][MX][2],f[MX][MX],r;

int cfs(int i, int p) {
  cnt[i]=1;
  for (int j: g[i]) if (j!=p) cnt[i]+=cfs(j,i);
  return cnt[i];
}
void solve(int i, int p, int d) {
  all[d]=i;
  if (i<st) for (int j=0; j<d; j++) r+=mul(f[j][d],cnt[all[j]]-cnt[all[j+1]],1);
  for (int j: g[i]) if (j!=p) solve(j,i,d+1);
}
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) {
    scanf("%d%d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dp[0][0][0].p=1;
  for (i=0; i<=n; i++) for (j=0; j<=n; j++) for (k=0; k<2; k++) if (dp[i][j][k].p>0) {
    dp[i+1][j][0]+=mul(dp[i][j][k],1,2);
    dp[i][j+1][1]+=mul(dp[i][j][k],1,2);
  }
  for (i=0; i<=n; i++) {
    f[i][i+1]=dp[i][0][0];
    for (j=i+2; j<=n; j++) {
      f[i][j]=f[i][j-1];
      f[i][j]+=dp[i][j-i-1][0];
    }
  }
  for (st=1; st<=n; st++) {
    cfs(st,0);
    solve(st,0,0);
  }
  printf("%d\n",int(r.p*pw((r.q*n)%md,md-2)%md));
  return 0;
}