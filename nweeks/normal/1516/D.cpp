#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e5 + 1;
const int MAXP = 18;

int rgt[MAXP][MAXN];

bool isPrime[MAXN];
vector<int> factors[MAXN];
void  sieve()
{
	for (int i(2); i < MAXN; ++i)
		isPrime[i] = true;
	for (int p(2); p < MAXN; ++p)
		if (isPrime[p])
		{
			factors[p] = {p};
			for (int j(2*p); j < MAXN; j += p)
			{
				isPrime[j] = false;
				factors[j].push_back(p);
			}
		}
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbElem, nbRequetes;
	cin >> nbElem >> nbRequetes;

	vector<int> arr(nbElem);
	for (auto &v : arr) cin >> v;
	sieve();
	vector<int> lst(MAXN, nbElem);

	rgt[0][nbElem] = nbElem;
	for (int i(nbElem-1); i >= 0; --i)
	{
		rgt[0][i] = nbElem;
		for (auto v : factors[arr[i]])
		{
			rgt[0][i] = min(rgt[0][i], lst[v]);
			lst[v] = i;
		}
		rgt[0][i] = min(rgt[0][i], rgt[0][i+1]);
	}
	for (int p(0); p < MAXP-1; ++p)
		for (int i(0); i <= nbElem; ++i)
			rgt[p+1][i] = rgt[p][rgt[p][i]];
	
	for (int iRequete = 0; iRequete < nbRequetes; ++iRequete) 
	{
		int deb, fin;
		cin >> deb >> fin;
		deb--, fin--;
		int sol(0);
		for (int p(MAXP-1); p >= 0; --p)
			if (rgt[p][deb] <= fin)
			{
				deb = rgt[p][deb];
				sol += (1 << p);
			}
		if (deb <= fin)
			sol++;
		cout << sol << '\n';
	}
}