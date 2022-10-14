#include <bits/stdc++.h>
using namespace std;

using lint = long long;

const int MAX = 1e7 + 5;

lint ans[MAX];
lint cnt[MAX];

void Main() {
  int c;
  cin >> c;
  cout << ans[c] << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(ans, -1, sizeof(ans));
  for (int i = 1; i < MAX; i++) {
    for (int j = i; j < MAX; j += i) {
      cnt[j] += i;
    }
  }
  for (int i = MAX - 1; i > 0; i--) {
    if (cnt[i] < MAX) {
      ans[cnt[i]] = i;
    }
  }

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}