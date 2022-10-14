#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

const lint PRIME[9] = {3, 11, 101, 1009, 10007, 100003, 1000003, 10000019, 100000007};

void Main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<int> pos(55, -1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (pos[a[i]] == -1) {
      pos[a[i]] = i;
    }
  }
  while (q--) {
    int c;
    cin >> c;
    cout << pos[c] + 1 << '\n';
    for (int i = 0; i < 55; i++) if (i != c && pos[i] < pos[c]) {
      pos[i]++;
    }
    pos[c] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}