#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  long long Xor, Sum;
  cin >> Xor >> Sum;

  if (Xor == Sum) {
    if (Xor == 0) {
      cout << 0 << "\n";
      return 0;
    } else {
      cout << 1 << "\n";
      cout << Xor << "\n";
      return 0;
    }
  }
  if (Xor > Sum) {
    cout << -1 << "\n";
    return 0;
  }

  // Xor - Sum = And
  long long x = (Sum - Xor) / 2;
  if (Sum % 2 != Xor % 2) {
    cout << -1 << "\n";
    return 0;
  }

  vector<long long> ans = {Xor, x, x};

  // a + b = a xor b + 2 * a & b
  // a & b = (Sum - Xor) / 2
  if ((Xor & x) == 0) {
    ans = {Xor | x, x};
  }

  cout << ans.size() << "\n";
  for (auto &i : ans) {
    cout << i << " ";
  }
  cout << "\n";

}