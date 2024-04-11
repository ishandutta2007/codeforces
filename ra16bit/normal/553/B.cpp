#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N,i,j,r[55];
long long m,f[55];
void solve(int n, int p, long long m) {
  if (n==0) return;
  for (int i=1; i<=n && i<=2; i++) {
  if (m<=f[n-i]) {
    solve(n-i,p+i,m);
    for (int j=p+i; j<=N; j++) r[j]+=i;
    for (int j=p+i-1, k=1; j>=p; j--, k++) r[j]=k;
    break;
  } else m-=f[n-i];
  }
}
int main() {
  cin>>N>>m;
  for (f[0]=i=1; i<=N; i++) for (j=1; j<=i && j<=2; j++) f[i]=min(m+1,f[i]+f[i-j]);
  solve(N,1,m);
  for (i=1; i<=N; i++) printf("%d%c",r[i],i==N?'\n':' ');
  return 0;
}