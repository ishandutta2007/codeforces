#include <bits/stdc++.h>
using namespace std;

int change(vector<int> &a, int n, int idd) {
	vector<int> id(n+1, -1);
	for (int i = 0; i < n; i++) {
		id[a[i]] = i;
	}

	int mex = 0;
	for (int i = 0; i <= n; i++) {
		if (id[i] == -1) {
			mex = i; break;
		}	
	}
	if (idd == -1) return mex;
	a[idd] = mex; 
	
	return change(a, n, -1);
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int mex_cur = change(a, n, -1);
	int left = n;

	vector<int> ans;
	vector<int> done(n);
	while (left) {
		if (mex_cur == n) {
			int gf = 0;
			for (int i = 0; i < n; i++) {
				if (!done[i]) {gf = i; break;}
			}

			int id = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] == gf) {
					id = i; break;
				}
			}
			ans.push_back(id+1);
			mex_cur = change(a, n, id);
		} else {
			ans.push_back(mex_cur + 1); done[mex_cur] = 1;
			mex_cur = change(a, n, mex_cur);
			left--; 
		}
	}

	cout << ans.size() << '\n';
	for (int i: ans) cout << i << ' ';
		cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}