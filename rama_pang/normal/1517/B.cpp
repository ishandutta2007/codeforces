#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  lint N, M;
  cin >> N >> M;
  vector<vector<lint>> A(N, vector<lint>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }

  vector<vector<lint>> ans;
  for (int rep = 0; rep < M; rep++) {
    pair<lint, lint> low = {1e18, -1};
    for (int i = 0; i < N; i++) {
      sort(begin(A[i]), end(A[i]));
      low = min(low, {A[i][0], i});
    }
    vector<lint> v;
    for (int i = 0; i < N; i++) {
      if (low.second == i) {
        v.emplace_back(A[i][0]);
        A[i].erase(begin(A[i]));
      } else {
        v.emplace_back(A[i].back());
        A[i].pop_back();
      }
    }
    ans.emplace_back(v);
  }
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << ans[j][i] << ' ';
    }
    cout << '\n';
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