#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXN = 1e5;

map<int, int> bestPath[MAXN];

int getBestLength(int to, int maxWeight)
{
	auto it = bestPath[to].lower_bound(maxWeight);
	--it;
	assert(it != bestPath[to].end());
	return it->second;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbSommets, nbAretes;
	cin >> nbSommets >> nbAretes;

	for (int i(0); i < nbSommets; ++i)
		bestPath[i][-1] = 0;

	while (nbAretes--)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		--from, --to;
		int lenBef = getBestLength(from, weight);
		auto it = bestPath[to].lower_bound(weight);
		while (it != bestPath[to].end() and it->second <= lenBef+1)
		{
			bestPath[to].erase(it);
			it = bestPath[to].lower_bound(weight);
		}
		it = bestPath[to].lower_bound(weight);
		--it;
		if (it->second < lenBef+1)
			bestPath[to][weight] = lenBef + 1;
	}

	int ans(0);
	for (int i(0); i < nbSommets; ++i)
		ans = max(ans, bestPath[i].rbegin()->second);
	cout << ans << endl;
}