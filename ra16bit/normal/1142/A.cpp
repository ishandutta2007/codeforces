#include <bits/stdc++.h>
using namespace std;
int n,k,a,b;
long long nk,x,d,z,r=1000000000000000000LL;
long long gcd(long long a, long long b) {
  return b?gcd(b,a%b):a;
}
int main() {
  scanf("%d%d%d%d",&n,&k,&a,&b);
  nk=n; nk*=k;
  for (x=1; x<=n; x++) {
    d=nk/gcd(nk,x*k-a-b);
    r=min(r,d); z=max(z,d);
    d=nk/gcd(nk,x*k-a+b);
    r=min(r,d); z=max(z,d);
    d=nk/gcd(nk,x*k+a-b);
    r=min(r,d); z=max(z,d);
    d=nk/gcd(nk,x*k+a+b);
    r=min(r,d); z=max(z,d);
  }
  cout<<r<<' '<<z;
  return 0;
}