#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#define all(x) begin(x), end(x)
#define sz(x) (int) x.size()



int solve() {
  string s;
  cin >> s;

  map<int, int> key;
  int cur = 0;

  for (int i = 0; i + 1 < s.size(); i++) {
    // cout << cur << " ";
    key[cur] = s[i] - 'a' + 1;
    key.emplace(cur - 1, 0);
    key.emplace(cur + 1, 0);
    if (key[cur - 1] == s[i + 1] - 'a' + 1) {
      cur--;
    } else if (key[cur + 1] == s[i + 1] - 'a' + 1) {
      cur++;
    } else if (key[cur - 1] == 0) {
      cur--;
    } else if (key[cur + 1] == 0) {
      cur++;
    } else {
      cout << "NO\n";
      return 0;
    }
  }
  key[cur] = s[s.size() - 1] - 'a' + 1;

  vector<int> used(30);
  string ans;

  for (auto &i : key) {
    if (i.second == 0) continue;
    if (used[i.second - 1] == 1) {
      cout << "NO\n";
      return 0;
    }
    // cout << i.first << " " << i.second << "\n";
    ans.push_back(i.second - 1 + 'a');
    used[i.second - 1] = 1;
  }

  for (int i = 0; i < 26; i++) {
    if (!used[i]) {
      ans.push_back(i + 'a');
    }
  }
  // cout << ans << " tmp ans\n";
  int adj[30][30] = {};
  for (int i = 0; i + 1 < ans.size(); i++) {
    adj[ans[i] - 'a'][ans[i + 1] - 'a'] = 1;
    adj[ans[i + 1] - 'a'][ans[i] - 'a'] = 1;
  }
  
  for (int i = 0; i + 1 < s.size(); i++) {
    int cnt = 0;
    cnt += adj[s[i] - 'a'][s[i + 1] - 'a'];
    cnt += adj[s[i + 1] - 'a'][s[i] - 'a'];
    if (cnt == 0) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  cout << ans << "\n";

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    solve();
  }
  return 0;
}