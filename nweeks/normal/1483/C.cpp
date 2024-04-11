#include <bits/stdc++.h>
#define int long long
using namespace std;

const int NBFEUILLES = 1 << 19;

int seg[2 * NBFEUILLES];

void upd(int iPos, int val)
{
	iPos += NBFEUILLES;
	seg[iPos] = val;
	while (iPos > 1)
	{
		iPos /= 2;
		seg[iPos] = max(seg[2*iPos], seg[2*iPos+1]);
	}
}

int query(int deb, int fin)
{
	if (deb < 0) deb = 0;
	deb += NBFEUILLES, fin += NBFEUILLES;
	int ret = -1e18;
	while (deb < fin)
	{
		if (deb % 2)
			ret = max(ret, seg[deb++]);
		if (!(fin%2))
			ret = max(ret, seg[fin--]);
		deb /= 2;
		fin /= 2;
	}
	if (deb == fin)
		ret = max(ret, seg[deb]);
	return ret;
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int nbBat;
	cin >> nbBat;
	vector<int> hauteur(nbBat), beaute(nbBat);
	for (auto &v : hauteur) cin >> v;
	for (auto &v : beaute) cin >> v;
	for (int i(0); i < 2 * NBFEUILLES; ++i)
		seg[i] = -1e18;

	vector<int> prv(nbBat), dp(nbBat, -1e18);
	prv[0] = -1;
	dp[0] = beaute[0];
	upd(0, beaute[0]);
	for (int iBat(1); iBat < nbBat; ++iBat)
	{
		prv[iBat] = iBat-1;
		while (prv[iBat] >= 0 and hauteur[prv[iBat]] > hauteur[iBat])
			prv[iBat] = prv[prv[iBat]];
		if (prv[iBat] != -1)
			dp[iBat] = max(dp[iBat], dp[prv[iBat]]);
		dp[iBat] = max(dp[iBat], beaute[iBat] + query(prv[iBat], iBat));
		if (prv[iBat] == -1)
			dp[iBat] = max(dp[iBat], beaute[iBat]);
		upd(iBat, dp[iBat]);
	}
	cout << dp.back() << endl;
}