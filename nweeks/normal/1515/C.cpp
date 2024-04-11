#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int nbBlocs, nbBats, diffMax;
		cin >> nbBlocs >> nbBats >> diffMax;
		vector<int> blocks(nbBlocs), order(nbBlocs);
		for (int iBlock = 0; iBlock < nbBlocs; ++iBlock) 
		{
			cin >> blocks[iBlock];
			order[iBlock] = iBlock;
		}
		sort(order.begin(), order.end(),
				[&](int i, int j) { return blocks[i] < blocks[j];});

		cout << "YES" << '\n';
		vector<int> iBat(nbBlocs);
		for (int i(0); i < nbBlocs; ++i)
			iBat[order[i]] = i % nbBats;
		for (auto v : iBat)
			cout << v +1 << ' ';
		cout << '\n';
	}
}