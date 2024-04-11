#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(void)
{
	int n, k, m;
	cin >> n >> k >> m;
	set<int> want, to_lft, to_rgt;
	int eachSide = k/2;
	int toSide = (ll)eachSide * (n-m)/(k-1);
	for (int i(0); i < m; ++i)
	{
		int v;
		cin >> v;
		want.insert(v);
	}
	if ((n - m) % (k-1))
		return false;
	for (int i(1); i <= n; ++i)
		if (!want.count(i))
		{
			if ((int)to_lft.size() == toSide)
				to_rgt.insert(i);
			else
				to_lft.insert(i);
		}
	auto it = want.lower_bound(*to_lft.rbegin());
	if (it != want.end() and *it < *to_rgt.begin())
		return true;
	int cntRemove(0);
	int tresh;
	if (it != want.end())
	{
		// Try with *it
		tresh = *it;
		for (auto v : to_rgt)
			if (v < tresh)
				++cntRemove;
		while (cntRemove%eachSide)
			++cntRemove;
		if (cntRemove + 1 <= (int)to_lft.size())
			return true;
	}
	// try with *it-1
	if (it == want.begin())
		return false;
	--it;
	tresh = *it;
	cntRemove = 0;
	for (auto v : to_lft)
		if (v > tresh) 
			++cntRemove;
	while (cntRemove%eachSide)
		++cntRemove;
	if (cntRemove+1 <= (int)to_rgt.size())
		return true;
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		cout << (solve() ? "yes" : "no") << '\n';
}