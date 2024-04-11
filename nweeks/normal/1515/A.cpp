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
		int nbPieces, aEviter;
		cin >> nbPieces >> aEviter;
		vector<int> pieces(nbPieces);
		for (auto &v : pieces) cin >> v;
		sort(pieces.begin(), pieces.end());
		int tot(0);
		for (auto v: pieces) tot += v;
		if (tot == aEviter)
		{
			cout << "NO\n";
			continue;
		}
		int curSum = 0;
		cout << "YES\n";
		for (int i(0); i < nbPieces; ++i)
		{
			if (curSum + pieces[i] == aEviter)
			{
				curSum += pieces[i+1] + pieces[i];
				cout << pieces[i+1] << ' ' << pieces[i] << ' ';
				i++;
			}
			else
			{
				curSum += pieces[i];
				cout << pieces[i] << ' ';
			}
		}
		cout << '\n';
	}
}