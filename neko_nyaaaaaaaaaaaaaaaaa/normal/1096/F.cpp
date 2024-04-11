#include <bits/stdc++.h>
using namespace std;

#define int long long
int M = 998244353;
int ft[200004];

int modpow(int n, int k, int MOD);
void init();

struct InversionCount{
	int n; vector<int> a;
	InversionCount(vector<int> a) {
		this->a = a;
		n = a.size()-1;
	}

	int merge_count(vector<int> &a, int left, int right) {
		int mid = (left + right)/2;

		int pt1 = left;
		int pt2 = mid+1;
		vector<int> final;

		int ans = 0;

		while (pt1 <= mid && pt2 <= right) {
			if (a[pt1] <= a[pt2]) {
				final.push_back(a[pt1]); pt1++;
			} else {
				final.push_back(a[pt2]); pt2++;
				ans += mid - pt1 + 1;
			}
		}
		while (pt1 <= mid) {
			final.push_back(a[pt1]); pt1++;
		}
		while (pt2 <= right) {
			final.push_back(a[pt2]); pt2++;
		}

		for (int i = 0; i < final.size(); i++) {
			a[i + left] = final[i];
		}

		return ans;
	}

	int inversion_count(vector<int> &a, int left, int right) {
		if (left == right) return 0;

		int mid = (right + left)/2;

		int x = inversion_count(a, left, mid);
		int y = inversion_count(a, mid+1, right);
		int z = merge_count(a, left, right);

		return x+y+z;
	}

	int solve() {
		return inversion_count(a, 1, n);
	}
};

int inv(vector<int> a) {
      vector<int> b(1);

      for (int i: a) {
            if (i != -1) {
                  b.push_back(i);
            }
      }

      InversionCount i(b);
      return i.solve();
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);
      init();

      int n; cin >> n;
      int m = 0;
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == -1) m++;
      }

      if (m == 0) {
            cout << inv(a) % M;
            return 0;
      }
      if (m == n) {
            int p = ft[m]*(m*(m-1) % M) % M;
            p = p*modpow(4, M-2, M);
            p %= M;

            p = p*modpow(ft[m], M-2, M) % M;
            cout << p;
            return 0;
      }

      vector<int> s(n+1, 1); s[0] = 0;
      for (int i = 0; i < n; i++) {
            if (a[i] != -1) {
                  s[a[i]] = 0;
            }
      }
      for (int i = 1; i <= n; i++) {
            s[i] += s[i-1];
      }

      int p = 0;
      int q = ft[m] % M;

      int pos = m;
      for (int i = 0; i < n; i++) {
            if (a[i] == -1) pos--;
            else {
                  int num = s[a[i]], pp = pos;

                  p += (((num*pp) % M) * ft[m-1]) % M;
                  p %= M;

                  num = m - s[a[i]]; pp = m - pos;
                  p += (((num*pp) % M) * ft[m-1]) % M;
                  p %= M;
            }
      }

      p += (ft[m] * (inv(a) % M)) % M;
      p %= M;

      int cas = ft[m]*(m*(m-1) % M) % M;
      cas = cas*modpow(4, M-2, M);
      cas %= M;

      p += cas;

      int ans = p*modpow(q, M-2, M);

      cout << ans % M;

      return 0;
}

int modpow(int n, int k, int MOD) {
      if (k == 0) return 1;
      int tmp = modpow(n, k/2, MOD);
      tmp = (tmp*tmp) % MOD;
      if (k % 2) tmp = (tmp*n) % MOD;
      return tmp;
}

void init() {
      ft[0] = 1;
      for (int i = 1; i <= 200000; i++) {
            ft[i] = (ft[i-1]*i) % M;
      }
}