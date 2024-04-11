#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long
#define S second
#define F first
#define pi pair<int, int>


using namespace std;

int gg(int i, int j, int f) {
	if ((j * (j - 1ll)) / 2ll > (i * (i - 1ll) / 2ll)) 
		return ((j * (j + 1ll)) / 2ll - (i * (i + 1ll) / 2ll)) * f;
	return 0;
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int m; cin >> m;
	int a; cin >> a;
	int b; cin >> b;
	int MAXN = 1e9 + 7;
	int mm[400004] = {};
	int ans[400004] = {};
	bool vis[400004] = {};
	mm[0] = 0;
	for (int i = 1; i <= 400000; ++i) 
		mm[i] = MAXN;
	priority_queue<pi, vector<pi>, greater<pi> > q;

	q.push({0, 0});
	while (!q.empty()) {
		auto p = q.top();
		q.pop();
		if (p.S - b >= 0 && !vis[p.S - b] && mm[p.S - b] > p.F) {
			mm[p.S - b] = p.F;
			q.push({p.F, p.S - b});
		}
		if (p.S + a <= 400000 && !vis[p.S + a] && mm[p.S + a] > max(p.F, p.S + a)) {
			mm[p.S + a] = max(p.F, p.S + a);
			q.push({max(p.F, p.S + a), p.S + a});
		}
		vis[p.S] = true;
	}
	for (int i = 0; i <= 400000; ++i)
		if (mm[i] != MAXN)
			ans[mm[i]]++;
	if (m <= 400000) {
		int r = ans[0];
		for (int i = 1; i <= m; ++i) {
			ans[i] += ans[i - 1];
			r += ans[i];
		}
		cout << r;
	} 
	else {
		int r = ans[0];
		for (int i = 1; i <= 400000; ++i) {
			ans[i] += ans[i - 1];
			r += ans[i];
		}
		int f = __gcd(a, b);
		int i;
		for (i = 400001; i <= m; ++i) {
			if ((i) % f == 0) {
				break;
			} else {
				r += ((i) / f + 1);
			}
		} 
		if (i == m) {
			cout << r;
			return 0;
		} 
		int j = ((m) / f) * f;
		r += ((m - j + 1ll) * (j / f + 1));
		j /= f;
		i /= f;
		r += gg(i, j, f);
		cout << r;
	}
}