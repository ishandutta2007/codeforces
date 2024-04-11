#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define ll long long

using namespace std;
const int root = 212, mod = 1e9 + 7, p = 239;
mt19937 rnd(time(nullptr));

vector <int> z(const string &s){
  int n = s.size();
  vector <int> res(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i){
    res[i] = max(0, min(r - i, res[i - l]));
    while (i + res[i] < n and s[res[i]] == s[i + res[i]])
      res[i]++;
    if (i + res[i] > r) l = i, r = i + res[i];
  }
  return res;
}

struct Hashing {
    vector <int> h, pw;
    Hashing(string s) {
      int n = s.size();
      h.resize(n + 1);
      pw.resize(n + 1);
      pw[0] = 1;
      for (int i = 1; i <= n; ++i)
        pw[i] = (ll)pw[i - 1] * p % mod;
      for (int i = 1; i <= n; ++i){
        h[i] = (ll)h[i - 1] * p % mod + s[i - 1] - 'a';
        h[i] %= mod;
      }
    }
    int getHash(int l, int r){
      int res = h[r + 1] - (ll)h[l] * pw[r - l + 1] % mod;
      res = (res % mod + mod) % mod;
      return res;
    }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(6);

  string s; cin >> s;

  int q; cin >> q;
  vector <int> ans(q, -1);

  vector <unordered_map <int, pair <int, int>>> qs(root);

  for (int i = 0; i < q; ++i){
    int k; string t; cin >> k >> t;
    if (t.size() >= root){
      vector <int> res = z(t + '?' + s), ids;
      for (int j = t.size() + 1; j < t.size() + 1 + s.size(); ++j){
        if (res[j] == t.size()) ids.push_back(j);
      }
      int got = mod;
      for (int j = k - 1; j < ids.size(); ++j){
        got = min(got, ids[j] - ids[j - k + 1]);
      }
      if (got < mod)
        ans[i] = got + t.size();
    } else {
      Hashing hs(t);
      qs[t.size()][hs.getHash(0, t.size() - 1)] = {k, i};
    }
  }

  Hashing hs(s);

  for (int i = 1; i < root; ++i) {
    if (qs[i].empty()) continue;
    map <int, vector <int>> ids;
    for (int j = 0; j + i - 1 < s.size(); ++j){
      int cur = hs.getHash(j, j + i - 1);
      if (qs[i].find(cur) == qs[i].end()) continue;
      ids[cur].push_back(j);
      if (ids[cur].size() >= qs[i][cur].first){
        int var = ids[cur].back() - ids[cur][ids[cur].size() - qs[i][cur].first] + i;
        if (ans[qs[i][cur].second] == -1 or ans[qs[i][cur].second] > var){
          ans[qs[i][cur].second] = var;
        }
      }
    }
  }

  for (auto &x: ans) cout << x << '\n';

}