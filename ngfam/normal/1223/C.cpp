#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int ntest; cin >> ntest;
  while(ntest--) {
    int n; cin >> n;
    vector<int> p(n + 1);

    for(int i = 1; i <= n; ++i) cin >> p[i];

    sort(p.rbegin(), p.rend() - 1);
    int a, x; cin >> x >> a;
    int b, y; cin >> y >> b;


    long long k; cin >> k;

    int low = 1, high = n, ans = -1;
    while(low <= high) {
      int mid = (low + high) >> 1;

      vector<int> cnt(mid + 1);
      vector<pair<int, int>> id;
      for(int i = 1; i <= mid; ++i) {
        if(i % a == 0) cnt[i] += x;
        if(i % b == 0) cnt[i] += y;
        id.emplace_back(cnt[i], i);
      }

      long long s = 0;
      sort(id.rbegin(), id.rend());
      for(int i = 0; i < id.size(); ++i) {
        int val = p[i + 1];
        s += 1LL * val * id[i].first / 100;
      }

      if(s >= k) {
        ans = mid;
        high = mid - 1;
      }
      else low = mid + 1;
    }
    cout << ans << endl;
  }

  return 0;
}