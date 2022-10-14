#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  int ans = 0;
  vector<int> abc(n);
  const auto Update = [&](int x) {
    if (!(0 <= x && x + 2 < n)) return;
    ans -= abc[x];
    abc[x] = (s[x] == 'a' && s[x + 1] == 'b' && s[x + 2] == 'c');
    ans += abc[x];
  };

  for (int i = 0; i < n; i++) {
    Update(i);
  }
  while (q--) {
    int i;
    char x;
    cin >> i >> x;
    i--;
    s[i] = x;
    for (int j = i - 3; j <= i + 3; j++) {
      Update(j);
    }
    cout << ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) Main();  
}