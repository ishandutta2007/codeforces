#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int sum = 0;
int a[200005];
int m1[200005] = {};
std::vector<int> p;

void add(int i)
{
	sum += p[a[i]] * (2ll * m1[a[i]] + 1ll);
	m1[a[i]]++;
}

void sub(int i)
{
	m1[a[i]]--;
	sum -= p[a[i]] * (2ll * m1[a[i]] + 1ll);
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	int t; cin >> t;
	p.resize(n); for (int o = 0; o < n; o++) { cin >> p[o]; a[o] = p[o];}
	sort(p.begin(), p.end());
	for (int i = 0; i < n; ++i)
		a[i] = lower_bound(p.begin(), p.end(), a[i]) - p.begin();
	int bsize = 500;
	std::map<pair<int, int>, std::vector<int> > m;
	vector<pair<int, int> > q(t); for (int o = 0; o < t; o++) { cin >> q[o].first >> q[o].second; m[q[o]].pb(o);}
	sort(q.begin(), q.end(), [](pair<int, int> a, pair<int, int> b) { return (((a.first / 500) < (b.first / 500)) || (((a.first / 500) == (b.first / 500)) && (((a.second) < (b.second))))); });
	std::vector<int> res(t);
	int l = 0;
	int r = -1;
	int L, R;
	for (int i = 0; i < t; ++i)
	{
		if (!m[q[i]].empty())
		{
			L = q[i].first - 1;
			R = q[i].second - 1;
			while (r < R)
				add(++r);
			while (l > L)
				add(--l);
			while (r > R)
				sub(r--);
			while (l < L)
				sub(l++);
			for (int o : m[q[i]])
				res[o] = sum;
			m[q[i]].clear();
		}
	}
	for (int i = 0; i < t; ++i)
		cout << res[i] << "\n";
}