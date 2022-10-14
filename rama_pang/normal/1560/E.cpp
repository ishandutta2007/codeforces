#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  string t;
  cin >> t;
  vector<int> cntT(26), cntS(26);
  for (auto i : t) cntT[i - 'a']++;

  const auto IsPossible = [&](vector<int> cntS, vector<int> cntT) -> pair<bool, string> {
    int d = 0;
    for (int i = 0; i < 26; i++) if (cntT[i] > 0) d++;
    map<int, vector<int>> ok;
    for (int i = 0; i < 26; i++) {
      if (cntT[i] == 0) continue;
      if (cntS[i] == 0) return {false, ""};
      if (cntT[i] % cntS[i] != 0) return {false, ""};
      ok[cntT[i] / cntS[i]].emplace_back(i);
    }
    for (int i = 1; i <= d; i++) {
      if (ok[i].size() != 1) {
        return {false, ""};
      }
    }
    string res;
    for (int i = 1; i <= d; i++) {
      res.push_back('a' + ok[i][0]);
    }
    return {true, res};
  };
  const auto Construct = [&](string init, string del) {
    string res;
    for (auto i : del) {
      res += init;
      string nw;
      for (auto j : init) {
        if (j == i) {
          continue;
        }
        nw.push_back(j);
      }
      init = nw;
    }
    return res;
  };
  string ans;
  for (int i = 0; i < int(t.size()); i++) {
    cntS[t[i] - 'a']++;
    ans.push_back(t[i]);
    auto ck = IsPossible(cntS, cntT);
    if (ck.first) {
      if (Construct(ans, ck.second) == t) {
        cout << ans << ' ' << ck.second << '\n';
        return;
      }
    }
  }
  cout << -1 << '\n';
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