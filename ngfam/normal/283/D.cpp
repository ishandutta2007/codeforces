#include<bits/stdc++.h>
#define int long long

using namespace std;

main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  vector<int> a(n), b(n);
  for(int &x : a) cin >> x;

  for(int i = 0; i < n; ++i) {
    int x = a[i];
    while(x % 2 == 0) {
      x /= 2;
      b[i]++;
    }
  }

  vector<int> f(n + 1, n + 1);

  int answer = n + 1;
  for(int i = 0; i < n; ++i) {
    f[i] = i;
    int cur = a[i];
    while(cur % 2 == 0) cur /= 2;
    for(int j = i - 1; j >= 0; --j) {
      if(a[j] % cur == 0) {
        /// y has no 2 as prime factor
        if(a[i] % 2 == 1) f[i] = min(f[i], f[j] + i - j - 1);
        /// y has all the prime factor
        if(b[j] + i - j == b[i] || i - j - 1 >= b[i]) f[i] = min(f[i], f[j] + i - j - 1);
      }
    }
    answer = min(answer, f[i] + n - i - 1);
  }

  cout << answer << endl;

  return 0;
}