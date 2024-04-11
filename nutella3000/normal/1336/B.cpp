#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 2e9 + 7;
const int max_n = 2e5 + 3;

int rig(vector<int> &a, int x) {
	int l = -1;
	int r = a.size();
	while(r - l > 1) {
		int m = ((l + r) >> 1);
		if (a[m] < x) l = m;
		else r = m;
	}
	return r;
}

int ri(vector<int> &a, int x) {
	int res = rig(a, x);
	if (res == a.size()) return inf;
	return a[res];
}


int mid(vector<int> &a, double mi) {
	int q = rig(a, mi);
	int q1 = q - 1;

	//cout << q << " " << q1 << " " << mi << '\n';

	if (q == a.size() || (q1 >= 0 && mi - a[q1] < a[q] - mi)) return a[q1];
	if (q == a.size()) return inf;
	return a[q];
}

int dista(int x, int y, int z) {
	return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
}


int solve(vector<int> &a, vector<int> &b, vector<int> &c) {
	int res = 3e18;
	for(int i : a) {
		int j = ri(b, i);
		int k = mid(c, ((double)j + i) / 2);

		if (j == inf || k == inf) continue;

		//cout << i << " " << j << " " << k << '\n';

		res = min(res, dista(i, j, k));

		//cout << res << '\n';

		k = ri(c, i);
		j = mid(b, ((double)k + i) / 2);

		res = min(res, dista(i, j, k));
	}

	return res;
}


void solve() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	vector<int> a(n1), b(n2), c(n3);
	for(int i = 0;i < n1;i++) cin >> a[i];
	for(int i = 0;i < n2;i++) cin >> b[i];
	for(int i = 0;i < n3;i++) cin >> c[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());


	int res1 = solve(a, b, c);
	//int res2 = inf, res3 = inf;
	int res2 = solve(b, a, c);
	int res3 = solve(c, a, b);

	cout << min(res1, min(res2, res3)) << '\n';
}





signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);

   	int t;
   	cin >> t;
   	while(t--) {
   		solve();
   	}
}