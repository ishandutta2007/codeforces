#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  using lint = long long;
  int N;
  cin >> N;
  vector<vector<int>> A(N);
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    A[i].resize(x);
    for (int j = 0; j < x; j++) {
      cin >> A[i][j];
    }
  }
  int M;
  cin >> M;
  vector<vector<int>> B(M);
  for (int i = 0; i < M; i++) {
    B[i].resize(N);
    for (int j = 0; j < N; j++) {
      cin >> B[i][j];
      B[i][j]--;
    }
  }
  sort(begin(B), end(B));
  priority_queue<pair<int, vector<int>>> pq;
  const auto Get = [&](vector<int> b) {
    int res = 0;
    for (int i = 0; i < N; i++) {
      res += A[i][b[i]];
    }
    return res;
  };
  vector<int> b;
  for (int i = 0; i < N; i++) {
    b.emplace_back(A[i].size() - 1);
  }
  set<vector<int>> vis;
  pq.emplace(Get(b), b);
  while (!pq.empty()) {
    auto [score, vec] = pq.top();
    pq.pop();
    if (!binary_search(begin(B), end(B), vec)) {
      for (auto i : vec) {
        cout << i + 1 << ' ';
      }
      cout << '\n';
      return 0;
    }
    for (int i = 0; i < N; i++) {
      if (vec[i] > 0) {
        vec[i]--;
        if (vis.count(vec) == 0) {
          vis.emplace(vec);
          pq.emplace(Get(vec), vec);
        }
        vec[i]++;
      }
    }
  }
  cout << -1 << '\n';
  return 0;
}