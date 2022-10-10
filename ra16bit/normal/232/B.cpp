#include <iostream>
using namespace std;
const int MX=102,md=1000000007;
int n,k,i,j,e,c[MX][MX],f[MX][MX*MX];
long long m,p[MX],q[MX];
bool ifq;
long long pw(long long a, long long b) {
  if (b==0) return 1LL;
  if (b&1) return (a*pw(a,b-1))%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
int main() {
  cin>>n>>m>>k;
  for (i=0; i<=n; i++) {
    c[i][0]=1;
    for (j=1; j<=i; j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%md;
  }
  for (i=0; i<=n; i++) {
    p[i]=pw(c[n][i],m/n);
	q[i]=(p[i]*c[n][i])%md;
  }
  f[0][0]=1;
  for (i=0; i<n; i++) {
    ifq=(i<(m%n));
    for (j=0; j<=k; j++) if (f[i][j]) for (e=0; e<=n && j+e<=k; e++)
	  f[i+1][j+e]=(f[i+1][j+e]+f[i][j]*(ifq?q[e]:p[e]))%md;
  }
  cout<<f[n][k]<<'\n';
  return 0;
}