// LUOGU_RID: 91280322
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long i64;

const int N = 200005;
int q;
map<i64, vector<pair<int, int>>> qwq;
map<i64, vector<int>> qy;
int fa[N];
i64 ans[N];

int find(int x) {
  while (x != fa[x])
    x = fa[x] = fa[fa[x]];
  return x;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> q;
  for (int i = 1; i <= q; i++) {
    char c;
    i64 x;
    cin >> c >> x;
    if (c == '+')
      qwq[x].push_back({i, -1});
    else if (c == '-') {
      auto &tp = qwq[x].back();
      tp.second = i;
    } else {
      qy[x].push_back(i);
    }
  }

  for (auto &tp : qwq) {
    auto &x = tp.second.back();
    if (x.second == -1) 
      x.second = q;
    tp.second.push_back({q + 1, q + 1});
  }

  for (auto tp : qy) {
    int lt = 0, res = tp.second.size();
    for (int x : tp.second) {
      fa[x] = x;
      if (x > 1)
        fa[x - 1] = lt;
      lt = x;
    }
    fa[q + 1] = lt;

    for (i64 v = tp.first; res; v += tp.first) {
      if (qwq.find(v) == qwq.end()) {
        res = 0;
        for (int i = find(fa[q + 1]); i; i = find(i - 1))
          ans[i] = v;
        break;
      }

      int lt = 0;
      for (pair<int, int> tt : qwq[v]) {
        int vv = lower_bound(tp.second.begin(), tp.second.end(), tt.first) - tp.second.begin() - 1;
        if (vv != -1)
          for (int i = find(tp.second[vv]); i > lt; i = find(i - 1)) {
            res--;
            ans[i] = v;
            fa[i] = fa[i - 1];
          }
        lt = tt.second;
      }
    }
  }

  for (int i = 1; i <= q; i++)
    if (ans[i])
      cout << ans[i] << '\n';
}