#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	ll n;
	cin >> n;
	vector<ll> a(n); for (int o = 0; o < n; ++o) { cin >> a[o]; }
	vector<ll> b(n); for (int o = 0; o < n; ++o) { cin >> b[o]; }
	std::vector<ll> fa(n+1, 0);
	std::vector<ll> tfa(n+1, 0);
	for (int i = n-1; i >= 0; --i)
	{
		fa[i] = fa[i+1] + tfa[i+1];
		tfa[i] = tfa[i + 1] + a[i];
	}
	std::vector<ll> ba(n+1, 0);
	for (int i = n-1; i >= 0; --i)
	{
		ba[i] = ba[i+1] + (n - 1ll - i) * a[i];
	}
	std::vector<ll> fb(n+1, 0);
	std::vector<ll> tfb(n+1, 0);
	for (int i = n-1; i >= 0; --i)
	{
		fb[i] = fb[i+1] + tfb[i+1];
		tfb[i] = tfb[i + 1] + b[i];
	}
	std::vector<ll> bb(n+1, 0);
	for (ll i = n-1; i >= 0; --i)
	{
		bb[i] = bb[i+1] + (n - 1ll - i) * b[i];
	}

	std::vector<ll> pre(2 * n + 5, 0);
	pre[0] = 0;
	for (ll i = 1; i < 2 * n; ++i)
	{
		ll j = i / 2;
		if((i & 1) && (j & 1))
			pre[i] = pre[i-1] + i * a[j];
		else if((!(i & 1)) && (j & 1))
			pre[i] = pre[i-1] + i * b[j];
		else if((i & 1) && (!(j & 1)))
			pre[i] = pre[i-1] + i * b[j];
		else if((!(i & 1)) && (!(j & 1)))
			pre[i] = pre[i-1] + i * a[j];
	}
	ll ma = 0;
	for (ll i = 0; i < 2 * n; ++i)
	{
		ll j = i / 2;
		ll re = 0;
		if((!(i & 1)) && (j & 1))
			re = pre[i] + fb[j + 1] + tfb[j + 1] * (i + 1ll) + tfa[j] * (n - j + i) + ba[j];
		else if((!(i & 1)) && (!(j & 1)))
			re = pre[i] + fa[j + 1] + tfa[j + 1] * (i + 1ll) + tfb[j] * (n - j + i) + bb[j];
		ma = max(ma, re);
	}
	cout << ma;
}