#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://github.com/nweeks1/UltiSnips
struct rangeMax
{
	vector<int> seg;
	int p, deb;

	rangeMax(int N)
	{
		p = 0;
		while ((1<<p) < N) ++p;
		seg.assign((1<<(1+p)), 1e18);
		deb = (1<<p)-1;
	}

	void update(int id, int val)
	{
		id += deb;
		seg[id] = val;
		while (id)
		{
			id = (id-1)/2;
			seg[id] = min(seg[2*id+1], seg[2*id+2]);
		}
	}

	int query(int l, int r)
	{
		int ret(1e18);
		l += deb;
		r += deb;
		while (l < r)
		{
			if (l%2==0)
				ret = min(ret, seg[l]);
			if (r%2)
				ret = min(ret, seg[r]);
			l /= 2;
			r = (r-2)/2;
		}
		if (l == r)
			ret = min(ret, seg[r]);
		return ret;
	}
};

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbVilles;
	cin >> nbVilles;
	vector<int> a(nbVilles), c(nbVilles), ordre(nbVilles);
	for (int iVille = 0; iVille < nbVilles; ++iVille) 
	{
		cin >> a[iVille] >> c[iVille];
		ordre[iVille] = iVille;
	}

	sort(ordre.begin(), ordre.end(), [&](int i, int j)
			{
			return a[i] < a[j] or (a[i] == a[j] and c[i] < c[j]);
			});

	vector<int> dp1(nbVilles);

	rangeMax seg1(nbVilles), seg2(nbVilles);
	dp1[nbVilles-1] = 0;
	seg1.update(nbVilles-1, 0);
	seg2.update(nbVilles-1, a[ordre[nbVilles-1]]);

	for (int iOrdre(nbVilles-2); iOrdre >= 0; --iOrdre)
	{
		int iVille = ordre[iOrdre];
		int lo(iOrdre), up(nbVilles-1);
		while (lo < up)
		{
			int mid = (lo + up+1) / 2;
			if (a[ordre[mid]] - a[iVille] <= c[iVille])
				lo = mid;
			else
				up = mid-1;
		}
		dp1[iOrdre] = 1e18;
		if (lo > iOrdre)
			dp1[iOrdre] = min(dp1[iOrdre], seg1.query(iOrdre+1, lo));
		if (lo < nbVilles - 1)
			dp1[iOrdre] = min(dp1[iOrdre], seg2.query(lo+1, nbVilles-1) - a[iVille]- c[iVille]);
		seg1.update(iOrdre, dp1[iOrdre]);
		seg2.update(iOrdre, dp1[iOrdre] + a[iVille]);
	}
	for (auto v : c)
		dp1[0] += v;

	cout << dp1[0] << endl;
}