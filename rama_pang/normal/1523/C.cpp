#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<int> st;
  vector<vector<int>> ans;
  for (int i = 0; i < N; i++) {
    if (A[i] == 1) {
      st.emplace_back(A[i]);
      ans.emplace_back(st);
    } else {
      while (!st.empty() && st.back() + 1 != A[i]) {
        st.pop_back();
      }
      assert(!st.empty() && st.back() + 1 == A[i]);
      st.back() += 1;
      ans.emplace_back(st);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      if (j > 0) cout << '.';
      cout << ans[i][j];
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