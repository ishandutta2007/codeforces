#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M, P;
  cin >> N >> M >> P;

  vector<vector<int>> A(N, vector<int>(M));
  vector<vector<pair<int, int>>> ls(P + 1);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
      ls[A[i][j]].emplace_back(i, j);
    }
  }

  const long long INF = 1e18;
  vector<vector<long long>> dist(N, vector<long long>(M, INF));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (A[i][j] == 1) {
        dist[i][j] = i + j;
      }
    }
  }

  const int BLOCK = 500;

  for (int p = 1; p < P; p++) {
    if (ls[p].size() < BLOCK && ls[p + 1].size() < BLOCK) {
      for (auto [r1, c1] : ls[p]) {
        for (auto [r2, c2] : ls[p + 1]) {
          dist[r2][c2] = min(dist[r2][c2], dist[r1][c1] + abs(r1 - r2) + abs(c1 - c2));
        }
      }
    } else {
      static vector<vector<long long>> d(N, vector<long long>(M));
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          d[i][j] = INF;
        }
      }
      static vector<tuple<long long, int, int>> st;
      for (auto [r, c] : ls[p]) {
        st.push_back({dist[r][c], r, c});
      }
      sort(begin(st), end(st));
      reverse(begin(st), end(st));

      queue<pair<int, int>> q;
      const auto Push = [&](int r, int c, int dt) {
        if (0 <= r && r < N && 0 <= c && c < M && d[r][c] == INF) {
          d[r][c] = dt;
          q.emplace(r, c);
        }
      };

      while (!q.empty() || !st.empty()) {
        if (q.empty()) {
          auto [dt, r, c] = st.back();
          st.pop_back();
          Push(r, c, dt);
          continue;
        }
        auto [r, c] = q.front();
        q.pop();
        while (!st.empty() && d[r][c] == get<0>(st.back())) {
          auto [dt, r, c] = st.back();
          st.pop_back();
          Push(r, c, dt);
        }
        Push(r - 1, c, d[r][c] + 1);
        Push(r + 1, c, d[r][c] + 1);
        Push(r, c - 1, d[r][c] + 1);
        Push(r, c + 1, d[r][c] + 1);
      }

      for (auto [r, c] : ls[p + 1]) {
        dist[r][c] = d[r][c];
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (A[i][j] == P) {
        cout << dist[i][j] << '\n';
      }
    }
  }
  return 0;
}