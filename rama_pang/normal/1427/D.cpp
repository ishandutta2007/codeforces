#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
  }

  vector<vector<int>> ans;
  for (int rep = 0; rep + 1 < N; rep++) {
    // for (auto i : A) cout << i << " "; cout << " A\n";
    int pos = -1;
    for (int i = 0; i < N; i++) {
      if (A[i] == rep) {
        pos = i;
      }
    }
    ans.emplace_back();
    auto &v = ans.back();
    for (int i = 0; i < rep; i++) {
      v.emplace_back(1);
    }
    v.emplace_back(pos - rep + 1);
    v.emplace_back(N - pos - 1);
    
    vector<vector<int>> B;
    int c = 0;
    for (auto i : v) {
      B.emplace_back();
      for (int j = 0; j < i; j++) {
        B.back().emplace_back(A[c++]);
      }
    }
    reverse(begin(B), end(B));
    A.clear();
    for (auto i : B) {
      for (auto j : i) {
        A.emplace_back(j);
      }
    }
    reverse(begin(A), end(A));
    if (rep & 1) {
      reverse(begin(v), end(v));
    }
  }
  if (N % 2 == 0) {
    ans.emplace_back();
    for (int i = 0; i < N; i++) {
      ans.back().emplace_back(1);
    }
  }

  int cnt = 0;
  for (auto &v : ans) {
    vector<int> vv;
    for (auto i : v) {
      if (i > 0) {
        vv.emplace_back(i);
      }
    }
    v = vv;
    if (v.size() > 1) {
      cnt++;
    }
  }

  cout << cnt << "\n";
  for (auto &v : ans) {
    if (v.size() < 2) {
      continue;
    }
    cout << v.size();
    for (auto i : v) {
      cout << " " << i;
    }
    cout << "\n";
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