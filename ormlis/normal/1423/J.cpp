#include <iostream>
#include <vector>

typedef long long ll;
typedef __int128 lll;

const ll MOD = 1e9 + 7;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll _n;
    cin >> _n;
    lll n = _n;
    n /= 2;
    lll val = (n / 2 + 1) * (n / 2 + 1);
    if (n % 2 == 0)
      cout << (ll)(val % MOD) << '\n';
    if (n % 2 == 1)
      cout << (ll)((val + (n / 2 + 1)) % MOD) << '\n';
  }
  return 0;
}