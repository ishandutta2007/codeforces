#include <stdio.h>
#include <iostream>

using namespace std;

const long long mod = 1000000007ll;
const int N = 100010;
const int SIGMA = 26;

long long fac[N];
int cnt[SIGMA];

char str[N];
int n;

long long pw(int x, int y) {
  if(y <= 0) {
    return 1ll;
  }
  long long r = pw(x, y/2);
  r = (r * r) % mod;
  if(y%2) {
    r = (x * r) % mod;
  }
  return r;
}
int main() {
  scanf("%d", &n);
  scanf("%s", str);
  fac[0] = 1ll;
  for(int i = 0;i <= n;i++) {
    if(i > 0) {
      fac[i] = (fac[i-1] * i) % mod;
    }
    cnt[str[i]-'A']++;
  }
  int c = 0;
  for(int i = 0;i < SIGMA;i++) {
    if(cnt[i] > c) {
      c = cnt[i];
    }
  }
  int tmp = 0;
  for(int i = 0;i < SIGMA;i++) {
    tmp += (cnt[i] == c);
  }
  long long ans = pw(tmp, n);
  cout << ans << endl;
  return 0;
}