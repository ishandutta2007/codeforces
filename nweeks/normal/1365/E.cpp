#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())

using ll = long long;

void solve()
{
	int nbElem;
	cin >> nbElem;

	vector<ll> elem(nbElem);
	for (auto &v : elem)
		cin >> v;
	ll ans(0);
	for (int i(0); i < nbElem; ++i)
		for (int j(i); j < nbElem; ++j)
			for (int k(j); k < nbElem; ++k)
				ans = max(ans, elem[i]|elem[j]|elem[k]);
	cout << ans << endl;
}

int main(void)
{
	int nbTests(1);
	//cin >> nbTests;
	for (int i(0); i < nbTests; ++i)
		solve();
}