#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int N, M, K;
  cin >> N >> M >> K;
  if (K != 1ll * N * M - 1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
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