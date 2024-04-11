#include <bits/stdc++.h>

using namespace std;

long long f(long long n) {
  if(n == 1) return 1;
  long long ret = n;
  for(long long i = 2; i * i <= n; ++i) {
    if(n % i == 0) ret = (ret / i) * (i - 1);
    while(n % i == 0) n /= i;
  }
  if(n > 1) ret = (ret / n) * (n - 1);
  return ret;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  long long n, k;
  cin >> n >> k;

  long long ans = f(n);

  for(long long i = 2; i <= k; ++i) {
    if(ans == 1) {
      break;
    }
    if(i % 2 == 1) ans = f(ans);
  }
  cout << ans % int(1e9 + 7) << endl;

  return 0;
}