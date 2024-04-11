#include <cstdio>
#include <iostream>
using namespace std;
int n,i,j,k,a[111],b[111];
long long r=1LL;
bool u[111];
long long gcd(long long a, long long b) {
  return b?gcd(b,a%b):a;
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    b[a[i]]++;
  }
  for (i=1; i<=n; i++) if (b[i]==0) {
    puts("-1");
    return 0;
  }
  for (i=1; i<=n; i++) if (!u[i]) {
    for (j=i, k=0; !u[j]; j=a[j], k++) u[j]=true;
    if (k%2==0) k/=2;
    r=r/gcd(r,k)*k;
  }
  cout<<r<<'\n';
  return 0;
}