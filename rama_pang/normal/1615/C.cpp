#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;
int cnt[MAX][20];

void Main() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;

  int ans = 1e9;
  // Use even number of operations
  if (count(begin(a), end(a), '1') == count(begin(b), end(b), '1')) {
    int score = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] != b[i]) score += 1;
    }
    ans = min(ans, score);
  }
  // Use odd number
  // So we use even, then toggle
  int pref = 0;
  int suff = 0;
  int cnta = 0, cntb = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) suff++;
    cnta += a[i] - '0';
    cntb += b[i] - '0';
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) suff--;
    if (a[i] == '1' && cntb == n - cnta + 1) ans = min(ans, pref + suff + 1);
    if (a[i] == b[i]) pref++;    
  }

  if (ans > 1e8) ans = -1;
  cout << ans << '\n';
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