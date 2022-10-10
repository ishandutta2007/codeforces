#include <bits/stdc++.h>
using namespace std;
const int MX=300300,md=1000000007;
int n,m,i,j,x,g,r,a[MX],c[MX],cnt[MX],dp[MX],d[11],cur[11];
int gcd(int a, int b) { return b?gcd(b,a%b):a; }
void rec(int l, int cur) {
  if (l==m) {
    ++cnt[cur];
    return;
  }
  rec(l+1,cur);
  rec(l+1,cur*d[l]);
}
int C(int n, int m) {
  for (int i=0; i<m; i++) cur[i]=n-i;
  for (int i=m; i>1; i--) for (int j=0; j<m; j++) if (cur[j]%i==0) {
    cur[j]/=i; break;
  }
  long long res=1;
  for (int i=0; i<m; i++) res=(res*cur[i])%md;
  return res;
}
int main() {
  for (i=2; i<MX; i++) if (!c[i]) for (j=i; j<MX; j+=i) c[j]=i;
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    if (a[i]==1) { puts("1"); return 0; }
    g=gcd(g,a[i]);
  }
  if (g>1) { puts("-1"); return 0; }
  for (i=0; i<n; i++) {
    for (x=a[i], m=0; x>1; m++) {
      d[m]=c[x];
      while (c[x]==d[m]) x/=d[m];
    }
    rec(0,1);
  }
  for (r=2; r<=n && r<=7; r++) {
    for (i=MX-1; i>=1; i--) if (cnt[i]>=r) {
      dp[i]=C(cnt[i],r);
      for (j=i+i; j<MX; j+=i) if (cnt[j]>=r) dp[i]=(dp[i]+md-dp[j])%md;
    }
    if (dp[1]>0) break;
  }
  printf("%d\n",r);
  return 0;
}