#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string S;
  cin >> S;

  const auto Solve = [&](string A) -> pair<int, vector<int>> {
    int bal = 0;
    for (auto i : A) {
      if (i == 'L') bal++;
      else bal--;
    }
    if (bal < 0) return {1e9, {}};

    // Construct
    vector<int> lastL;
    vector<int> lastR;
    vector<int> link(A.size(), -1);
    for (int id = 0; id < int(A.size()); id++) {
      auto i = A[id];
      if (i == 'L') {
        if (lastR.size() > 0) {
          link[id] = lastR.back();
          lastR.pop_back();
          lastL.emplace_back(id);
        } else {
          lastL.emplace_back(id);
        }
      } else {
        if (lastL.size() > 0) {
          link[id] = lastL.back();
          lastL.pop_back();
          lastR.emplace_back(id);
        } else {
          lastR.emplace_back(id);
        }
      }
    }

    int cnt = 0;
    for (int i = 0; i < int(A.size()); i++) {
      if (link[i] == -1) cnt++;
    }

    int N = A.size();
    vector<int> vis(N);
    vector<vector<int>> seq[2][2];

    int adj[2][2] = {};
    for (int i = N - 1; i >= 0; i--) {
      if (!vis[i]) {
        int u = i;
        vector<int> cur;
        while (u != -1) {
          cur.emplace_back(u);
          vis[u] = 1;
          u = link[u];
        }
        reverse(begin(cur), end(cur));
        seq[A[cur.front()] == 'R'][A[cur.back()] == 'R'].emplace_back(cur);
        // for (auto j : cur) cout << j << ' '; cout << '\n';
      }
    }

    // for (int i = 0; i < 2; i++) {
    //   for (int j = 0; j < 2; j++) {
    //     cout << seq[i][j].size() << ' ';
    //   }
    //   cout << '\n';
    // }

    const auto Dfs = [&](const auto &self, int start, vector<int> &r) -> void {
      // cout << start << " hi\n";
      for (int i = 0; i < 2; i++) {
        if (!seq[start][i].empty()) {
          auto save = seq[start][i].back();
          seq[start][i].pop_back();
          self(self, i ^ 1, r);
          while (!save.empty()) {
            r.emplace_back(save.back());
            save.pop_back();
          }
        }
      }
    };

    vector<int> startL;
    Dfs(Dfs, 0, startL);

    vector<int> startR;
    Dfs(Dfs, 1, startR);

    reverse(begin(startL), end(startL));
    reverse(begin(startR), end(startR));

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        assert(seq[i][j].empty());
      }
    }

    if (startL.empty()) return {cnt - 1, {startR}};
    if (startR.empty()) return {cnt - 1, {startL}};

    assert(A[startL.back()] == 'R');
    assert(A[startR.back()] == 'L');

    if (startL.back() < startR.back()) {
      startL.emplace_back(startR.back());
      startR.pop_back();
      for (auto i : startR) startL.emplace_back(i);
      return {cnt - 1, startL};
    } else {
      assert(startR.back() < startL.back());
      startR.emplace_back(startL.back());
      startL.pop_back();
      for (auto i : startL) startR.emplace_back(i);
      return {cnt - 1, startR};
    }
  };

  auto ans = Solve(S);
  for (int i = 0; i < int(S.size()); i++) {
    S[i] ^= 'L' ^ 'R';
  }
  ans = min(ans, Solve(S));

  cout << ans.first << '\n';
  for (int i = 0; i < int(ans.second.size()); i++) {
    cout << ans.second[i] + 1 << " \n"[i + 1 == ans.second.size()];
  }
  return 0;
}