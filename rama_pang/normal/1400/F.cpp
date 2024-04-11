#include <bits/stdc++.h>
using namespace std;

class AhoCorasick {
 public:
  int n;
  vector<int> sl;
  vector<int> bad;
  vector<vector<int>> d;
  vector<vector<int>> nxt;

  AhoCorasick() : n(1), sl(1, 0), bad(1, 0), d(1, vector<int>(10, 0)), nxt(1, vector<int>(10, 0)) {}

  void Add(vector<int> s) {
    int u = 0;
    for (auto i : s) {
      if (!nxt[u][i]) {
        sl.emplace_back(0);
        bad.emplace_back(0);
        d.emplace_back(vector<int>(10, 0));
        nxt.emplace_back(vector<int>(10, 0));
        nxt[u][i] = n++;
      }
      u = nxt[u][i];
    }
    bad[u] = 1;
  }

  void Build() {
    queue<int> q;
    q.emplace(0);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      bad[u] |= bad[sl[u]];
      for (int i = 0; i < 10; i++) {
        int v = nxt[u][i];
        if (v != 0) {
          sl[v] = d[sl[u]][i];
          d[u][i] = v;
          bad[v] |= bad[u];
          q.emplace(v);
        } else {
          d[u][i] = d[sl[u]][i];
        }
      }
    }
  }

  bool Bad(int x) {
    return bad[x];
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  string s;
  cin >> s;
  int x;
  cin >> x;
  AhoCorasick ac;

  function<void(int)> Generate = [&](int sum) {
    static vector<int> xprime;
    if (sum < 0) return;
    if (sum == 0) {
      for (int i = 0; i < (int) xprime.size(); i++) {
        int sub = 0;
        for (int j = i; j < (int) xprime.size(); j++) {
          sub += xprime[j];
          if (sub != x && x % sub == 0) {
            return;
          }
        }
      }
      ac.Add(xprime);
      return;
    }
    for (int add = 1; add < 10; add++) {
      xprime.push_back(add);
      Generate(sum - add);
      xprime.pop_back();
    }
  };

  Generate(x);
  ac.Build();

  vector<vector<int>> dp(s.size() + 1, vector<int>(ac.n, 1e9));
  dp[0][0] = 0;
  for (int i = 0; i < (int) s.size(); i++) {
    int t = s[i] - '0';
    for (int j = 0; j < ac.n; j++) if (!ac.Bad(j)) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
      if (!ac.Bad(ac.d[j][t])) {
        dp[i + 1][ac.d[j][t]] = min(dp[i + 1][ac.d[j][t]], dp[i][j]);
      }
    }
  }

  cout << *min_element(begin(dp[s.size()]), end(dp[s.size()])) << "\n";
  return 0;
}