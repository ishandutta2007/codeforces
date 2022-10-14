#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const lint MOD = 998244353;
lint n, m, L, R;

lint power(lint n, lint x) {
  if (x == 0) return 1;
  if (x & 1) return n * power(n, x - 1) % MOD;
  lint res = power(n, x / 2);
  return res * res % MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> m >> L >> R;

  if (L == R) {
    cout << 1 << "\n";
    return 0;
  }  

  int all = R - L + 1, odd, even;
  odd = even = all / 2;
  if (all % 2 == 1) {
    if (L % 2 == 1) { // L is odd, R is odd
      odd++;
    } else {
      even++;
    }
  }

  lint poss;
  if (n % 2 == 1 && m % 2 == 1) { // nm is odd
    // poss = power(2, n * m);
    poss = power(odd + even, n * m);
  } else { // nm is even
    // poss = power(2, n * m - 1);
    poss = power(max(odd, even) - min(odd, even), n * m) + power(odd + even, n * m);
    poss %= MOD;
    if (poss & 1) poss += MOD;
    poss /= 2;
  }

  cout << poss << "\n";
  return 0;
}