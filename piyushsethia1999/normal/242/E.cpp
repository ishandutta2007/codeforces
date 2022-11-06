#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;
//stores sum of the segment
std::vector<std::vector<ll> > seg;

//stores how much to increment to each
std::vector<std::vector<bool> > lazy;

void build(ll i, std::vector<ll>& v, ll node, ll s, ll e)
{
	if(s == e) {
		seg[i][node] = v[s];
		return;
	}
	ll m = (s+e)>>1;
	build(i, v, 2 * node, s, m);
	build(i, v, 2 * node + 1, m + 1, e);
	seg[i][node] = seg[i][node * 2 + 1] + seg[i][node * 2];
}

void updateRange(ll i, ll node, ll s, ll e, ll l, ll r)
{
	if(l > e || s > r)
		return;
	if(s >= l && e <= r)
	{

		seg[i][node] = (e-s+1-seg[i][node]);
		lazy[i][node] = (!(lazy[i][node]));
		return;
	}
	ll m = (s+e)/2;

	if(lazy[i][node]) {
		seg[i][2 * node] = m - s + 1 - seg[i][2 * node];
		seg[i][2 * node + 1] = (e - m - seg[i][2 * node + 1]);
		lazy[i][2 * node] = lazy[i][node] ^ lazy[i][2 * node];
		lazy[i][2 * node + 1] = lazy[i][node] ^ lazy[i][2 * node + 1];
		lazy[i][node] = false;
	}

	updateRange(i, 2*node, s, m, l, r);
	updateRange(i, 2*node + 1, m + 1, e, l, r);

	seg[i][node] = seg[i][2*node] + seg[i][2*node + 1];
}

ll queryRange(ll i, ll node, ll s, ll e, ll l, ll r)
{
	if(l > e || s > r)
		return 0;
	if(l <= s && e <= r)
		return seg[i][node];
	ll m = (s + e)/2;
	if(lazy[i][node]) {
		seg[i][2 * node] = m - s + 1 - seg[i][2 * node];
		seg[i][2 * node + 1] = (e - m - seg[i][2 * node + 1]);
		lazy[i][2 * node] = lazy[i][node] ^ lazy[i][2 * node];
		lazy[i][2 * node + 1] = lazy[i][node] ^ lazy[i][2 * node + 1];
		lazy[i][node] = false;
	}
	return (queryRange(i, 2*node, s, m, l, r) + queryRange(i, 2*node+1, m + 1, e, l, r));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#endif
	ll n, m;
	cin >> n;
	seg.resize(20, std::vector<ll> (4*n, 0));
	lazy.resize(20, std::vector<bool> (4*n, false));
	std::vector<std::vector<ll> > a(20, std::vector<ll> (n, 0));
	ll k;
	for (ll i = 0; i < n; ++i)
	{
		cin >> k;
		ll j = 0;
		while(k)
		{
			if(k & 1)
				a[j][i]++;
			j++;
			k >>= 1;
		}
	}
	for (ll i = 0; i < 20; ++i)
		build(i, a[i], 1, 0, n-1);
	cin >> m;
	for (ll i = 0; i < m; ++i)
	{
		ll q, l, r, v;
		cin >> q >> l >> r; l--; r--; q--;
		if(q)
		{
			cin >> v;
			ll j = 0;
			while(v)
			{
				if(v & 1)
					updateRange(j, 1, 0, n-1, l, r);
				j++;
				v >>= 1;
			}
		}
		else {
			ll res = 0;
			for (ll i = 0; i < 20; ++i) {
				ll y =  queryRange(i, 1, 0, n-1, l, r);
				res += ((1 << i) * y);
			}
			cout << res << "\n";
		}
	}
}