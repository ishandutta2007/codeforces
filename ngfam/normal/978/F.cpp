#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, k; cin >> n >> k;
  vector<int> a(n);

  for(int &x : a) cin >> x;

  vector<pair<int, int>> id;
  for(int i = 0; i < n; ++i) {
    id.emplace_back(a[i], i);
  }

  sort(id.begin(), id.end());

  int  tot = 0, cur = 1;

  vector<int> ans(n);
  for(int i = 1; i < n; ++i) {
    if(id[i].first > id[i - 1].first) {
      tot += cur;
      cur = 0;
    }
    cur++;

    ans[id[i].second] = tot;
  }

  for(int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    if(a[x] > a[y]) --ans[x];
    if(a[y] > a[x]) --ans[y];
  }

  for(int i = 0; i < n; ++i) cout << ans[i] << " ";

  return 0;
}