#include <bits/stdc++.h>
using namespace std;
int t,cnt;
long long a,b,n;
int main() {
  cin>>t;
  while (t--) {
    cin>>a>>b>>n;
    cnt=0;
    while (a<=n && b<=n) {
      if (a<b) a+=b; else b+=a;
      cnt++;
    }
    cout<<cnt<<'\n';
  }
  return 0;
}