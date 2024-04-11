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
	vector<int> occ[MAXV];
	vector<int> pref[MAXV];
	for (int v(0); v < MAXV; ++v)
		pref[v].resize(n);
	for (int i(0); i < n; ++i)
	{
		cin >> a[i];
		--a[i];
		occ[a[i]].push_back(i);
		for (int v(0); v < MAXV; ++v)
			pref[v][i] = (i ? pref[v][i-1] : 0) + (a[i]==v);
	}
	int ans(0);
	for (int v1(0); v1 < MAXV; ++v1)
	{
		int cnt = SZ(occ[v1]);
		ans = max(ans, cnt);
		for (int len(1); len <= cnt-len; ++len)
		{
			int deb = occ[v1][len-1];
			int fin = occ[v1][cnt-len];
			for (int v2(0); v2 < MAXV; ++v2)
				ans = max(ans, 2*len + pref[v2][fin-1] - pref[v2][deb]);
		}
	}

	
	cout << ans<< '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int __t(1);
	cin >> __t;
	while (__t--)
		solve();
}