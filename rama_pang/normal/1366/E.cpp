#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  vector<int> st;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.back()] >= a[i]) {
      st.pop_back();
    }
    st.emplace_back(i);
  }
  
  long long ans = 1;
  const int mod = 998244353;
  if (a[st[0]] != b[0]) {
    cout << 0 << "\n";
    return 0;
  }
  for (int i = 0, p = 0; i < m; i++) {
    while (p < st.size() && a[st[p]] < b[i]) {
      p++;
    }
    if (p == st.size() || a[st[p]] != b[i]) {
      cout << 0 << "\n";
      return 0;
    }
    if (i > 0) {
      ans *= st[p] - st[p - 1];
      ans %= mod;
    }
  }

  cout << ans << "\n";
  return 0;
}