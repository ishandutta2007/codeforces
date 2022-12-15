#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

void solve(void)
{
	int n, m;
	cin >> n >> m;
	vector<pair<set<int>, ll> > G(n);

	for (int i(0); i < n;++i)
		cin >> G[i].second;
	for (int i(0); i< m;++i)
	{
		int u, v;
		cin >> u >> v;
		--u,--v;
		G[v].first.insert(u);
	}

	sort(G.begin(), G.end());

	ll ans(0);
	int l(0);
	while (l < n)
	{
		int r = l;
		ll s(0);
		while (r < n and G[l].first == G[r].first)
			s += G[r++].second;
		if (SZ(G[l].first) > 0)
			ans = gcd(ans,s);
		l = r;
	}
	cout << ans << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}