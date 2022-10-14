#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    auto Get = [&](long long x) {
      string s = to_string(x);
      long long sum = 0;
      for (auto i : s) sum += i - '0';
      return __gcd(x, sum);
    };
    while (Get(n) == 1) n++;
    cout << n << '\n';
  }
  return 0;
}