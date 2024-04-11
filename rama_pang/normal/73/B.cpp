#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  map<string, int> mp2;
  map<int, int> mp;
  vector<string> names;
  for (int i = 0; i < n; i++) {
    string s;
    int a;
    cin >> s >> a;
    mp2[s] = a;
    names.emplace_back(s);
  }
  sort(begin(names), end(names));
  for (auto i : mp2) {
    int jj = lower_bound(begin(names), end(names), i.first) - begin(names);
    mp[jj] = i.second;
  }
  int m;
  cin >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  while (a.size() < n) {
    a.emplace_back(0);
  }
  sort(begin(a), end(a));
  reverse(begin(a), end(a));
  string me_;
  cin >> me_;
  int me = lower_bound(begin(names), end(names), me_) - begin(names);
  int anslo, anshi;
  {
    lint mine = 1ll * n * a.back() + 1ll * mp[me] * n - me;
    vector<lint> others;
    for (auto i : mp) {
      if (i.first != me) {
        others.emplace_back(1ll * i.second * n - i.first);
      }
    }
    sort(begin(others), end(others));
    reverse(begin(others), end(others));
    multiset<lint> add;
    for (int i = 0; i + 1 < n; i++) {
      add.emplace(1ll * a[i] * n);
    }
    int bigger = 0;
    for (int i = 0; i + 1 < n; i++) {
      lint need = mine - others[i];
      auto it = add.upper_bound(need);
      if (it == end(add)) {
        break;
      }
      add.erase(it);
      bigger += 1;
    }
    anslo = bigger + 1;
  }

  {
    lint mine = 1ll * a.front() * n + 1ll * mp[me] * n - me;
    vector<lint> others;
    a.erase(begin(a));
    for (auto i : mp) {
      if (i.first != me) {
        others.emplace_back(1ll * i.second * n - i.first);
      }
    }
    sort(begin(others), end(others));
    multiset<lint> add;
    for (int i = 0; i + 1 < n; i++) {
      add.emplace(1ll * a[i] * n);
    }
    int bigger = 0;
    for (int i = 0; i + 1 < n; i++) {
      lint need = mine - others[i];
      auto it = add.upper_bound(need);
      if (it == begin(add)) {
        bigger += 1;
        continue;
      }
      add.erase(prev(it));
    }
    // for (auto i : others) cout << i << " "; cout << me << "\n";
    anshi = bigger + 1;
  }

  cout << anshi << " " << anslo << "\n";
  return 0;
}