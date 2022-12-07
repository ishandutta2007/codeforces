#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for(int &x : a) cin >> x;

  vector<int> answer(q);
  vector<vector<pair<int, int>>> queries(n);

  for(int i = 0; i < q; ++i) {
    int l, x; cin >> l >> x;
    queries[--l].emplace_back(x, i);
  }

  vector<int> f(1 << 20);
  f[0] = 1;

  int ans = 1;
  for(int i = 0; i < n; ++i) {
    if(f[a[i]]) ans = (ans * 2) % (1000000007);
    else {
      for(int j = 0; j < f.size(); ++j) if(f[j]) {
        f[j ^ a[i]] = 1;
      }
    }

    for(auto &p : queries[i]) {
      answer[p.second] = f[p.first] * ans;
    }
  }

  for(int x : answer) cout << x << "\n";

  return 0;
}