#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

int ans = 1;
int cc = 1;
int dsu[MAX];
multiset<int> big;
multiset<int> small;

void Delete(int s) {
  if (small.count(s)) {
    small.erase(small.find(s));
  } else {
    assert(big.count(s));
    ans -= s;
    big.erase(big.find(s));
    if (small.size() > 0) {
      auto it = prev(end(small));
      big.emplace(*it);
      ans += *it;
      small.erase(it);
    } 
  }
}
void Insert(int s) {
  // cerr << "INS" << endl;
  if (big.size() > 0 && *begin(big) < s) {
    auto it = begin(big);
    ans -= *it;
    small.emplace(*it);
    big.erase(it);
    ans += s;
    big.emplace(s);
  } else {
    small.emplace(s);
  }
}
int Find(int x) {
  return dsu[x] < 0 ? x : dsu[x] = Find(dsu[x]);
}
int Unite(int x, int y) {
  x = Find(x), y = Find(y);
  if (x == y) {
    if (small.size() > 0) {
      auto it = prev(end(small));
      big.emplace(*it);
      ans += *it;
      small.erase(it);
    }
    return 0;
  }
  Insert(-dsu[x] - dsu[y]);
  Delete(-dsu[x]);
  Delete(-dsu[y]);
  dsu[x] += dsu[y];
  dsu[y] = x;
  return 1;
}
void Main() {
  memset(dsu, -1, sizeof(dsu));
  int n, m;
  cin >> n >> m;
  big.emplace(1);
  for (int i = 1; i < n; i++) small.emplace(1);
  for (int r = 0; r < m; r++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (!Unite(u, v)) {
      cc += 1;
    }
    cout << ans - 1 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) Main();  
}