#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;
const int MAXV = 200;

void solve(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &v : a)
	{
		cin >> v;
		--v;
	}
	vector<int> pref[MAXV];
	vector<int> suff[MAXV];
	for (int v(0); v < MAXV; ++v)
	{
		pref[v].resize(n);
		suff[v].resize(n);
	}
	pref[a[0]][0]++;
	suff[a[n-1]][n-1]++;
	for (int i(1); i < n; ++i)
	{
		pref[a[i]][i]++;
		for (int v(0); v < MAXV; ++v)
			pref[v][i] += pref[v][i-1];
	}
	for (int i(n-2); i >= 0; --i)
	{
		suff[a[i]][i]++;
		for (int v(0); v < MAXV; ++v)
			suff[v][i] += suff[v][i+1];
	}

	int ans(1);
	for (int deb(0); deb < n; ++deb)
		for (int fin(deb+1); fin < n; ++fin)
		{
			int bst_outside(0);
			int bst_inside(0);
			for (int v(0); v < MAXV; ++v)
			{
				bst_outside = max(bst_outside, min(suff[v][fin], pref[v][deb]));
				if (deb < fin)
					bst_inside = max(bst_inside, pref[v][fin-1] - pref[v][deb]);
			}
			ans = max(ans, bst_inside+bst_outside*2);
		}
	cout<<ans<<'\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int __t(1);
	cin >> __t;
	while (__t--)
		solve();
}