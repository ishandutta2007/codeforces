#include <bits/stdc++.h>
using namespace std;

class Fenwick {
 public:
  int sz;
  vector<int> tree;

  Fenwick(int sz) : sz(sz), tree(sz) {}

  void Modify(int p, int x) {
    for (int i = p; i < sz; i |= i + 1) {
      tree[i] += x;
    }
  }

  int Query(int p) {
    int z = 0;
    for (int i = p + 1; i > 0; i &= i - 1) {
      z += tree[i - 1];
    }
    return z;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    string S;
    cin >> S;
    int N = S.size();
    map<int, vector<int>> mp;
    for (int i = 0; i < N; i++) {
      mp[S[i]].emplace_back(i);
    } 
    vector<char> perm;
    for (auto &i : mp) perm.emplace_back(i.first);
    sort(begin(perm), end(perm));
    string ans;
    long long max_score = -1;
    do {
      string T;
      for (auto p : perm) {
        for (int i = 0; i < mp[p].size(); i++) {
          T.push_back(p);
        }
      }
      map<int, vector<int>> ls;
      for (int i = 0; i < N; i++) {
        ls[T[i]].emplace_back(i);
      } 
      Fenwick F(N);
      for (auto &i : ls) {
        reverse(begin(i.second), end(i.second));
      }
      long long score = 0;
      for (int i = 0; i < N; i++) {
        int u = ls[S[i]].back(); ls[S[i]].pop_back();
        score += u + F.Query(u) - i;
        F.Modify(0, +1);
        F.Modify(u, -1);
      }
      if (score > max_score) {
        max_score = score;
        ans = T;
      }
    } while (next_permutation(begin(perm), end(perm)));
    cout << ans << '\n';
  }
  return 0;
}