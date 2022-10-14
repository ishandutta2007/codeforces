#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;

template<typename T>
void Add(T &a, lint b) {
  a += b;
  a -= (a >= MOD) * MOD;
}

lint Power(lint x, lint y) {
  lint res = 1;
  for (; y; y /= 2, x = 1ll * x * x % MOD) {
    if (y & 1) {
      res = 1ll * res * x % MOD;
    }
  }
  return res;
} 

void Main() {
  int n;
  string s;
  cin >> n >> s;
  if (s.substr(0, 4) == "2020" || (s.substr(0, 3) == "202" && s.back() == '0') || (s[0] == '2' && s[1] == '0' && s[s.size() - 2] == '2' && s.back() == '0') || (s[0] == '2' && s[s.size() - 3] == '0' && s[s.size() - 2] == '2' && s[s.size() - 1] == '0') || (s[s.size() - 4] == '2' && s[s.size() - 3] == '0' && s[s.size() - 2] == '2' && s[s.size() - 1] == '0')) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}