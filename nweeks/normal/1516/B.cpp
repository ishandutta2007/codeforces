#include <bits/stdc++.h>
#define int long long
using namespace std;

bool solve()
{
	int nbElem;
	cin >> nbElem;

	vector<int> arr(nbElem);
	for (auto &v : arr) cin >> v;
	int curXor(0);
	for (int i(0); i < nbElem-1; ++i)
	{
		curXor ^= arr[i];

		int pos = i+1;
		bool ok = true;
		while (pos < nbElem)
		{
			int r = pos+1;
			int x = arr[pos];
			while (r < nbElem and x != curXor)
				x ^= arr[r++];
			if (x != curXor and (pos == i+1 or x))
			{
				ok = false;
				break;
			}
			pos = r;
		}
		if (ok) return true;
	}
	return false;
}

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		cout << (solve() ? "YES" : "NO") << endl;
}