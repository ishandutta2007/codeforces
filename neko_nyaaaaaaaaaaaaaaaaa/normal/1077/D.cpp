#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void out(vector<int> a) {
      for (int i: a) cout << i << ' ';
      exit(0);
}

int check(vector<int> &a, int k, int mid) {
      int c = 0;
      for (int i = 0; i < a.size(); i++) {
            c += a[i]/mid;
      }
      return c >= k;
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, k; cin >> n >> k;
      vector<int> a(200001);
      for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a[x]++;
      }

      int lo = 1, hi = 200000;
      while (lo < hi) {
            int mid = (lo + hi + 1)/2;

            if (check(a, k, mid)) {
                  lo = mid;
            } else {
                  hi = mid - 1;
            }
      }

      int c = lo;
      vector<int> ans;
      for (int i = 0; i < a.size(); i++) {
            int t = a[i]/c;

            while (t--) {
                  if (ans.size() == k) out(ans);
                  ans.push_back(i);
                  if (ans.size() == k) out(ans);
            }
      }

      return 0;
}