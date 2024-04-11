#include <bits/stdc++.h>
using namespace std;
int n,i,a,x,o,cnt[2][1100100];
long long r;
int main() {
  scanf("%d",&n);
  cnt[0][0]=1;
  for (i=1; i<=n; i++) {
    scanf("%d",&a);
    x^=a;
    o=(i&1);
    r+=cnt[o][x];
    cnt[o][x]++;
  }
  cout<<r<<'\n';
  return 0;
}