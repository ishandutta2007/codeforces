#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

inline ll pos(ll a)
{
	if (a > 0) return a;
	return -a;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	vector<bool> seen(m);
	for (auto &v : a)
	{
		cin >> v;
		if (seen[v%m])
		{
			cout << 0 << endl;
			return 0;
		}
		seen[v%m] = true;
	}

	ll ans(1);
	for (int i(0); i < n; ++i)
		for (int j(i+1); j<n; ++j)
			ans = (ans * pos(a[j] -a[i]))%m;
	cout << ans << endl;
}