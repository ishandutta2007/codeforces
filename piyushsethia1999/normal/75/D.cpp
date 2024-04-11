#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

ll max(ll a1, ll a2)
{
	return ((a1 > a2) ? (a1) : (a2));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, m;
	cin >> n >> m;
	std::vector<int> b(m);
	std::vector<std::vector<ll> > a(n);
	std::vector<ll> premax(n);
	std::vector<ll> postmax(n);
	std::vector<ll> sum(n);
	std::vector<ll> intmax(n);
	std::vector<ll> mi(n, -1000);
	int siz;
	for (int i = 0; i < n; ++i)
	{
		cin >> siz;
		a[i].resize(siz);
		for (int j = 0; j < siz; ++j) {
			cin >> a[i][j];
			mi[i] = max(a[i][j], mi[i]);
		}
		premax[i] = max(a[i][0], 0l);
		postmax[i] = max(a[i][siz - 1], 0l);
		ll pr = a[i][0];
		ll po = a[i][siz-1];
		intmax[i] = a[i][0];
		ll curr = a[i][0];
		for (int j = 1; j < siz; j++)
		{
			curr = max(a[i][j], curr+a[i][j]);
			intmax[i] = max(intmax[i], curr);

			pr += a[i][j];
			premax[i] = max(pr, premax[i]);

			po += a[i][siz - 1 - j];
			postmax[i] = max(po, postmax[i]);
		}
		sum[i] = pr;
	}
	print(sum, premax, postmax, intmax);
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		b[i]--;
	}
	ll ma = intmax[b[0]];
	ll curr = postmax[b[0]];
	ll me = mi[b[0]];
	for (int i = 1; i < m; i++)
	{
		ma = max(ma, max(curr + premax[b[i]], intmax[b[i]]));
		curr = max(postmax[b[i]], curr + sum[b[i]]);
		ma = max(ma, curr);
		me = max(me, mi[b[i]]);
	}
	if(me < 0)
		ma = me;
	cout << ma;
}