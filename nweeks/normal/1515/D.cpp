#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve()
{
	int nbChaussetes, nbGauches, nbDroites;
	cin >> nbChaussetes >> nbGauches >> nbDroites;
	
	vector<int> nbColGauches(nbChaussetes), nbColDroites(nbChaussetes);
	for (int i(0); i < nbGauches; ++i)
	{
		int c;
		cin >> c;
		c--;
		nbColGauches[c]++;
	}
	for (int i = 0; i < nbDroites; ++i) 
	{
		int c;
		cin >> c;
		c--;
		if (nbColGauches[c]) 
		{
			nbColGauches[c]--;
			continue;
		}
		nbColDroites[c]++;
	}
	int ret(0);

	int oddL(0), oddR(0);
	for (auto v : nbColGauches)
		oddL += v % 2;
	for (auto v: nbColDroites)
		oddR += v % 2;
	
	int m = min(oddL, oddR);
	ret += m;
	oddL -= m;
	oddR -= m;
	int pairsL(0), pairsR(0);
	for (auto v : nbColGauches)
		pairsL += v / 2;
	for (auto v : nbColDroites)
		pairsR += v / 2;
	
	while (oddL >= 2 and pairsR)
		ret += 2, oddL -= 2, pairsR--;
	while (oddR >= 2 and pairsL)
		ret += 2, oddR -= 2, pairsL--;
	ret += pairsL + pairsR + oddL + oddR;

	return ret;
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
		cout << solve() << '\n';
}