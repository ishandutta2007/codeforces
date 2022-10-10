#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,a[400200],b[200200],d[200200],s[200200];
long long r;
int gcd(int a, int b) { return b?gcd(b,a%b):a; }
void solve(int c) {
  for (int i=0; i<=c; i++) b[i]=0;
  for (int i=0; i<n; i++) {
    b[i%c]=max(b[i%c],a[i]);
    if (i) s[i]=s[i-1]+int(d[i]==c);
  }
  int cur=0;
  for (int i=n+n-1; i>=0; i--) {
    cur=(a[i]==b[i%c])?cur+1:0;
    if (cur>=n) cur=n-1;
    if (i<n) r+=s[cur];
  }
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    a[n+i]=a[i];
    d[i]=gcd(i,n);
  }
  for (j=1; j*j<=n; j++) if (n%j==0) {
    solve(j);
    if (j>1 && j<n/j) solve(n/j);
  }
  printf("%I64d\n",r);
  return 0;
}