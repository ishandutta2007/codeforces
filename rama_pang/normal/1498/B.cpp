#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(begin(a), end(a));
    reverse(begin(a), end(a));
    multiset<int> st;
    st.emplace(0);
    for (auto i : a) {
      if (*begin(st) + i > m) {
        st.emplace(0);
      }
      auto it = prev(st.upper_bound(m - i));
      assert(*it + i <= m);
      int v = *it + i;
      st.erase(it);
      st.emplace(v);
    }
    cout << st.size() << '\n';
  }
  return 0;
}