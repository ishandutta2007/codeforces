#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<pair<int, int>> ans;

  vector<int> st;
  vector<pair<int, int>> onetwo;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 0) {
      continue;
    }
    if (a[i] == 1) {
      st.emplace_back(i);
    } else if (a[i] == 2) {
      if (st.empty()) {
        cout << -1 << '\n';
        return;
      }
      onetwo.emplace_back(i, st.back());
      st.pop_back();
    }
  }

  set<int> rows;
  for (int i = 0; i < n; i++) {
    rows.emplace(i);
  }

  int cnt = 0;
  vector<int> h(n, -1);
  while (!st.empty()) {
    onetwo.emplace_back(st.back(), st.back());
    st.pop_back();
  }
  
  vector<int> ins(n, -1);
  sort(begin(onetwo), end(onetwo));
  for (auto i : onetwo) {
    ans.emplace_back(cnt, i.first);
    ans.emplace_back(cnt, i.second);
    rows.erase(cnt);
    h[i.first] = cnt++;
  }
  queue<int> q;
  for (int i = n - 1; i >= 0; i--) {
    if (h[i] >= 0) {
      q.emplace(i);
    }
    if (a[i] != 3) {
      continue;
    }
    bool paired = false;
    if (a[i] == 3 && !rows.empty() && !q.empty()) {
      auto it = rows.upper_bound(h[q.front()]);
      while (!q.empty() && it == end(rows)) {
        q.pop();
        it = rows.upper_bound(h[q.front()]);
      }
      if (it != end(rows)) {
        ans.emplace_back(*it, i);
        ans.emplace_back(*it, q.front());
        h[i] = *it;
        q.emplace(i);
        q.pop();
        rows.erase(it);
        paired = true;
      }
    }
    if (!paired) {
      cout << -1 << '\n';
      return;
    }
  }

  sort(begin(ans), end(ans));
  ans.resize(unique(begin(ans), end(ans)) - begin(ans));
  cout << ans.size() << '\n';
  for (auto i : ans) {
    cout << n - i.first << ' ' << i.second + 1 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}