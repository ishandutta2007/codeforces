#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> dansUniv(n);
	vector<int> univ(n), skill(n);
	for (auto &v : univ)
		cin >> v;
	for (auto &v : skill)
		cin >> v;
	for (int i(0); i < n; ++i)
		dansUniv[univ[i]-1].push_back(skill[i]);
	for (int i = 0; i < n; ++i) 
		sort(dansUniv[i].rbegin(), dansUniv[i].rend());
	vector<int> avecRang(n);
	vector<int> sol(n+2);

	for (int iUniv(0); iUniv < n; ++iUniv)
	{
		int tailleUni = dansUniv[iUniv].size();
		for (int i(1); i < tailleUni; ++i)
			dansUniv[iUniv][i] += dansUniv[iUniv][i-1];
		for (int k(1); k <= tailleUni; ++k)
			sol[k] += dansUniv[iUniv][tailleUni - tailleUni%k -1];
	}
	for (int k(1); k <= n; ++k)
		cout << sol[k]<< ' ';
	cout << '\n';
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while(tc--)
		solve();
}