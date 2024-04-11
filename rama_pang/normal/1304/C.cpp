#include <bits/stdc++.h>
using namespace std;

int N, M;
int L[105], R[105], T[105];
void solve() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> T[i] >> L[i] >> R[i];
  }

  pair<int, int> temp = {M, M};
  for (int i = 1; i <= N; i++) {
    int gap = T[i] - T[i - 1];
    temp.first -= gap;
    temp.second += gap;
    if (R[i] < temp.first || temp.second < L[i]) {
      cout << "NO\n";
      return;
    }
    temp.first = max(temp.first, L[i]);
    temp.second = min(temp.second, R[i]);
  }
  cout << "YES\n";
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}