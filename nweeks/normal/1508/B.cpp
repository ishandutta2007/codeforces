#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 2e18;
const int MAXN = 1e5 + 1;

int nbPerm[MAXN];

void init()
{
	nbPerm[0] = nbPerm[1] = 1;
	for (int i(2); i < MAXN; ++i)
		nbPerm[i] = min(INF, 2 * nbPerm[i-1]);
}

void solve()
{
	int nbElem, ordreVoulu;
	cin >> nbElem >> ordreVoulu;
	vector<int> ret;
	if (nbPerm[nbElem] < ordreVoulu)
	{
		cout << -1 << '\n';
		return ;
	}
	int prochain = 1;
	while (prochain <= nbElem)
	{
		if (nbPerm[nbElem-prochain] >= ordreVoulu)
		{
			ret.push_back(prochain++);
			continue;
		}
		int cur = prochain;
		while (ordreVoulu > nbPerm[nbElem-cur])
		{
			ordreVoulu -= nbPerm[nbElem-cur];
			cur++;
		}
		for (int i(cur); i >= prochain; --i)
			ret.push_back(i);
		prochain = cur+1;
	}
	for (auto v : ret) cout << v << ' ';
	cout << '\n';
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	init();

	int t;
	cin >> t;
	while (t--)
		solve();
}