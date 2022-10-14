#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  vector<string> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<tuple<char, int, int>> ans;

  vector<vector<int>> vis(N, vector<int>(M));
  for (int sx = 0; sx < N; sx++) {
    for (int sy = 0; sy < M; sy++) if (A[sx][sy] == '.' && vis[sx][sy] == 0) {
      vector<pair<int, int>> que;
      const auto Push = [&](int x, int y) {
        if (0 <= x && x < N && 0 <= y && y < M && A[x][y] == '.' && vis[x][y] == 0) {
          vis[x][y] = 1;
          que.emplace_back(x, y);
        }
      };
      Push(sx, sy);
      for (int i = 0; i < int(que.size()); i++) {
        Push(que[i].first - 1, que[i].second);
        Push(que[i].first + 1, que[i].second);
        Push(que[i].first, que[i].second - 1);
        Push(que[i].first, que[i].second + 1);
      }
      for (auto [x, y] : que) {
        ans.push_back({'B', x, y});
      }
      reverse(begin(que), end(que));
      que.pop_back();
      for (auto [x, y] : que) {
        ans.push_back({'D', x, y});
        ans.push_back({'R', x, y});
      }
    }
  }

  cout << ans.size() << '\n';
  for (auto [c, x, y] : ans) {
    cout << c << ' ' << x + 1 << ' ' << y + 1 << '\n';
  }
  return 0;
}