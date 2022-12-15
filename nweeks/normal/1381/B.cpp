#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())

using ll = long long;

bool solve()
{
	int nbElem;
	cin >> nbElem;
	vector<int> p(nbElem*2);
	for (auto &v : p) cin >> v;
	vector<int> tailleBlocs;
	int cur(0); 
	while (cur < nbElem*2)
	{
		int r(cur+1);
		while (r < 2*nbElem and p[r] < p[cur])
			++r;
		tailleBlocs.push_back(r-cur);
		if (tailleBlocs.back() > nbElem)
			return false;
		cur = r;
	}
	vector<bool> can(nbElem+1);
	can[0] = true;
	for (auto v : tailleBlocs)
		for (int i(nbElem); i >= v; --i)
			can[i] = can[i] or can[i-v];
	return can[nbElem];
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbTests(1);
	cin >> nbTests;
	for (int i(0); i < nbTests; ++i)
		cout << (solve() ? "YES" : "NO") << '\n';;
}