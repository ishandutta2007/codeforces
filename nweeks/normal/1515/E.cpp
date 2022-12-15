#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 401;
int MOD, nbElem;

int sol[MAXN][MAXN]; // sol[x][y] : how many ways for x ? 
int validPerm[MAXN]; // validPerm[x] : how many ways to arrange x consecutives?
int binom[MAXN][MAXN];

void calcBinom()
{
	for (int lig(0); lig < MAXN; ++lig)
	{
		binom[lig][0] = binom[lig][lig] = 1;
		for (int col(1); col < lig; ++col)
		{
			binom[lig][col] = binom[lig-1][col-1] + binom[lig-1][col];
			if (binom[lig][col] >= MOD)
				binom[lig][col] -= MOD;
		}
	}
}

void calcValidPerms()
{
	for (int len(1); len < MAXN; ++len)
	{
		for (int lenDecreasing(1); lenDecreasing <= len; ++lenDecreasing)
			validPerm[len] += binom[len-1][lenDecreasing-1];
		validPerm[len] %= MOD;
	}
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> nbElem >> MOD;
	calcBinom();
	calcValidPerms();

	sol[0][0] = 1;
	for (int len(1); len <= nbElem; ++len)
		for (int nbActions(1); nbActions <= len; ++nbActions)
		{
			if (nbActions==len)
				sol[len][nbActions] += validPerm[len];
			for (int pref(1); pref < len-1; ++pref)
				if (pref <= nbActions)
				{
					sol[len][nbActions] += validPerm[pref] * sol[len-pref-1][nbActions-pref]
						% MOD  * binom[nbActions][pref]%MOD;
					sol[len][nbActions] %= MOD;
				}
		}
	int ret =0;
	for (int nbActions(1); nbActions <= nbElem; ++nbActions)
		ret += sol[nbElem][nbActions];
	cout << ret % MOD << endl;
}