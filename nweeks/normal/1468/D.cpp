#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int lenCorridor, nbCrack, a, b;
vector<int> crackers;

bool can(int want)
{
	int timeCaught = (a < b ? b-1 : lenCorridor - b);
	for (int i(0); i < want; ++i)
		if (timeCaught < crackers[i] + (want -i))
			return false;
	return true;
}

int solve()
{
	cin >> lenCorridor >>nbCrack >> a >> b;
	crackers.resize(nbCrack);
	for (auto &v : crackers)
		cin >> v;
	sort(crackers.begin(), crackers.end());
	int lo(0), up(min((int)crackers.size(), abs(a-b)-1));
	while (lo < up)
	{
		int mid = (lo + up + 1)/2;
		if (can(mid))
			lo = mid;
		else
			up = mid-1;
	}
	return lo;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin>> t;
	while (t--)
		cout << solve() << '\n';
}