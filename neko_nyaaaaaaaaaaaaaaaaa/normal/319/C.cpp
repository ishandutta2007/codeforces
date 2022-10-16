#include <bits/stdc++.h>
using namespace std;

struct CHT {
      vector<long long> a, b;

      double cross(int i, int j, int k) {
            return 1.d*(a[j] - a[i])*(b[k] - b[i]) - 1.d*(a[k] - a[i])*(b[j] - b[i]);
      }

      void add(long long A, long long B) {
            a.push_back(A);
            b.push_back(B);

            while (a.size() > 2 && cross(a.size() - 3, a.size() - 2, a.size() - 1) >= 0) {
                  a.erase(a.end() - 2);
			b.erase(b.end() - 2);
		}
      }

      long long query(long long x) {
            int l = 0, r = a.size() - 1;

            while (l < r) {
                  int mid = l + (r - l)/2;
			long long f1 = a[mid] * x + b[mid];
			long long f2 = a[mid + 1] * x + b[mid + 1];

			if (f1 > f2) l = mid + 1;
			else r = mid;
            }

            return a[l]*x + b[l];
      }
};

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<long long> a(n), b(n);
      for (int i = 0; i < n; i++) cin >> a[i];
      for (int i = 0; i < n; i++) cin >> b[i];

      CHT hull; long long ans;
      hull.add(b[0], 0);
      for (int i = 1; i < n; i++) {
            ans = hull.query(a[i]);
            hull.add(b[i], ans);
      }
      cout << ans;

      return 0;
}