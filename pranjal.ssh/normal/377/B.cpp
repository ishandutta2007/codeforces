#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, s; cin >> n >> m >> s;

	vector<int> a(m), b(n), c(n), id(n), aid(m);
	for (int i = 0; i < m; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	for (int i = 0; i < n; ++i) cin >> c[i];
	iota(id.begin(), id.end(), 0);
	iota(aid.begin(), aid.end(), 0);

	sort(aid.begin(), aid.end(), [&](int x, int y) {
		return a[x] < a[y];
	});
	sort(id.begin(), id.end(), [&](int x, int y) {
		return b[x] < b[y];
	});

	int st = 1, en = m;
	auto f = [&] (int mid) {
		int done = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		vector<int> soln(m);
		int j = n - 1;
		long long cost = 0;
		for (int i = m - 1; i >= 0; --i) {
			while (j >= 0 and b[id[j]] >= a[aid[i]]) pq.emplace(c[id[j]], id[j]), --j;
			if (done == 0) {
				if (pq.empty()) {
					cost = s + 1;
					break;
				}
				cost += pq.top().first;
				for (int k = i; k >= 0 and k >= i - mid + 1; --k) {
					soln[aid[k]] = pq.top().second;
				}
				pq.pop();
			}
			++done;
			if (done == mid) done = 0;
		}
		if (cost > s) soln.clear();
		return soln;
	};
	while (st < en) {
		int mid = (st + en) >> 1;
		if (!f(mid).empty()) en = mid;
		else st = mid + 1;
	}
	auto x = f(st);
	if (!x.empty()) {
		cout << "YES\n";
		for (int y : x) cout << y + 1 << " ";
	} else {
		cout << "NO\n";
	}

	return 0;
}