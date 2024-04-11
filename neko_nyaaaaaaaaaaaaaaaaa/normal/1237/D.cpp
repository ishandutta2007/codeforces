#include <bits/stdc++.h>
using namespace std;

void case_work(vector<int> a, int n) {
	int mx = *max_element(a.begin(), a.end());
	int mn = *min_element(a.begin(), a.end());

	if (mn >= (mx + 1)/2) {
		while (n--) {
			cout << "-1 ";
		}
		exit(0);
	}
}

const int N = 300002;
int t[2 * N];
int t2[2 * N];

void build(int n, vector<int> a) {
	for (int i = 0; i < n; i++) {
		t[n + i] = a[i];
		t2[n + i] = a[i];
	}
	for (int i = n - 1; i > 0; --i) {
		t[i] = min(t[i<<1], t[i<<1|1]);
		t2[i] = max(t2[i<<1], t2[i<<1|1]);
	}
}

int query(int n, int l, int r) { 
	r++;
	int res = 1000000007;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = min(res, t[l++]);
		if (r & 1) res = min(res, t[--r]);
	}
	return res;
}

int que2(int n, int l, int r) { 
	r++;
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = max(res, t2[l++]);
		if (r & 1) res = max(res, t2[--r]);
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i]; a.push_back(a[i]);
	}
	for (int i = 0; i < n; i++) {
		a.push_back(a[i]);
	}
	case_work(a, n);

	n *= 3;
	build(n, a);

	vector<int> nxt(n, -1);
	vector<int> nxt_stop(n, -1);
	for (int i = 0; i < 2*n/3; i++) {
		int stop = (a[i] + 1)/2 - 1; 
		// suppose x = a[i]
		// binary search to find the point we stop
		int lo = i+1, hi = n-1;
		while (lo < hi) {
			int mid = (lo + hi)/2;

			if (query(n, i, mid) <= stop) {
				hi = mid;
			} else {
				lo = mid+1;
			}
		}
		int stop_pt = lo;

		int cont = a[i] + 1;
		// continue finding something better
		lo = i+1, hi = n-1;
		while (lo < hi) {
			int mid = (lo + hi)/2;

			if (que2(n, i, mid) >= cont) {
				hi = mid;
			} else {
				lo = mid+1;
			}
		}
		int cont_pt = lo;

		// do we stop here or do we continue
		if (cont_pt < stop_pt) {
			nxt[i] = cont_pt;
		} else {
			nxt_stop[i] = stop_pt;
		}
	}		

	// now dp
	vector<int> dp(n);
	for (int i = 2*n / 3 - 1; i >= 0; i--) {
		int cur = i;
		if (nxt[cur] != -1) {
			dp[cur] = dp[nxt[cur]] + nxt[cur] - cur;
		} else {
			dp[cur] = nxt_stop[cur] - cur;
		}
	}
	for (int i = 0; i < n/3; i++) {
		cout << dp[i] << ' ';
	}

	return 0;
}