#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> A(N + 4);
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  vector<pair<int, int>> ans;
  vector<vector<int>> dp(N + 10, vector<int>(N + 10, -1));
  function<int(int, int)> Dp = [&](int pos, int hold) {
    if (pos > N) {
      return A[hold];
    }
    if (dp[pos][hold] != -1) {
      return dp[pos][hold];
    }
    int res = 2e9;
    if (hold == 0) {
      res = min(res, Dp(pos + 3, pos + 0) + max(A[pos + 1], A[pos + 2]));
      res = min(res, Dp(pos + 3, pos + 1) + max(A[pos + 0], A[pos + 2]));
      res = min(res, Dp(pos + 3, pos + 2) + max(A[pos + 0], A[pos + 1]));
    } else {
      res = min(res, Dp(pos + 2, hold) + max(A[pos], A[pos + 1]));
      res = min(res, Dp(pos + 2, pos) + max(A[hold], A[pos + 1]));
      res = min(res, Dp(pos + 1, 0) + max(A[pos], A[hold]));
    }
    return dp[pos][hold] = res;
  };
  function<int(int, int)> Trace = [&](int pos, int hold) {
    if (pos > N) {
      ans.emplace_back(hold, 0);
      return A[hold];
    }
    int res = 2e9;
    if (hold == 0) {
      res = min(res, Dp(pos + 3, pos + 0) + max(A[pos + 1], A[pos + 2]));
      if (res == Dp(pos, hold)) {
        ans.emplace_back(pos + 1, pos + 2);
        return Trace(pos + 3, pos); 
      }
      res = min(res, Dp(pos + 3, pos + 1) + max(A[pos + 0], A[pos + 2]));
      if (res == Dp(pos, hold)) {
        ans.emplace_back(pos + 0, pos + 2);
        return Trace(pos + 3, pos + 1); 
      }
      res = min(res, Dp(pos + 3, pos + 2) + max(A[pos + 0], A[pos + 1]));
      if (res == Dp(pos, hold)) {
        ans.emplace_back(pos + 0, pos + 1);
        return Trace(pos + 3, pos + 2); 
      }
    } else {
      res = min(res, Dp(pos + 2, hold) + max(A[pos], A[pos + 1]));
      if (res == Dp(pos, hold)) {
        ans.emplace_back(pos, pos + 1);
        return Trace(pos + 2, hold); 
      }
      res = min(res, Dp(pos + 2, pos) + max(A[hold], A[pos + 1]));
      if (res == Dp(pos, hold)) {
        ans.emplace_back(hold, pos + 1);
        return Trace(pos + 2, pos); 
      }
      res = min(res, Dp(pos + 1, 0) + max(A[pos], A[hold]));
      if (res == Dp(pos, hold)) {
        ans.emplace_back(hold, pos);
        return Trace(pos + 1, 0); 
      }
    }
    return dp[pos][hold] = res;
  };

  cout << Dp(1, 0) << "\n";
  Trace(1, 0);
  for (auto i : ans) {
    if (1 <= i.first && i.first <= N) {
      cout << i.first;
    }
    cout << " ";
    if (1 <= i.second && i.second <= N) {
      cout << i.second;
    }
    cout << "\n";
  }
  return 0;
}