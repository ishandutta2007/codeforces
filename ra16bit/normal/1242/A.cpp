#include <bits/stdc++.h>
using namespace std;
long long n,i;
int main() {
  cin>>n;
  for (i=2; i<=n && i<=1000000; i++) if (n%i==0) {
	while (n%i==0) n/=i;
	if (n==1) cout<<i; else cout<<1;
	return 0;
  }
  cout<<n;
  return 0;
}