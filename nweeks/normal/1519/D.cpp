#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 5001;

int sum[MAXN][MAXN];
int pref[MAXN], suff[MAXN];

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbElem;
	cin >> nbElem;
	vector<int> a(nbElem), b(nbElem);
	for (auto &v : a) cin >> v;
	for (auto &v : b) cin >> v;
	
	for (int i(0); i < nbElem; ++i)
	{
		sum[i][i] = a[i] * b[i];
		if (i+1 < nbElem)
			sum[i][i+1] = a[i] * b[i+1] + a[i+1] * b[i];
	}
	for (int diff(2); diff <= nbElem; ++diff)
		for (int deb(0); deb + diff <= nbElem; ++deb)
		{
			int fin = deb + diff;
			sum[deb][fin] = sum[deb+1][fin-1] + a[deb] * b[fin] + a[fin] * b[deb];
		}
	for (int i(0); i < nbElem; ++i)
		pref[i] = a[i] * b[i] + (i ? pref[i-1] : 0);
	for (int i(nbElem-1); i >= 0; --i)
		suff[i] = a[i] * b[i] + (i+1 < nbElem ? suff[i+1] : 0);

	int sol = 0;
	for (int deb(0); deb < nbElem; ++deb)
		for (int fin(deb); fin < nbElem; ++fin)
		{
			int curCost = sum[deb][fin];
			if (deb)
				curCost += pref[deb-1];
			if (fin < nbElem-1)
				curCost += suff[fin+1];
			sol = max(sol, curCost);
		}
	cout << sol << endl;
}