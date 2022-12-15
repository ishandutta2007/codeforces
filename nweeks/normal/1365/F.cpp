#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())

using ll = long long;

bool solve()
{
	int nbElem;
	cin >> nbElem;

	vector<int> a(nbElem), b(nbElem);
	for (auto &v  : a)
		cin >> v;
	for (auto &v : b)
		cin >> v;

	vector<pair<int, int>> lft(nbElem/2), rgt(nbElem/2);
	for (int i(0); i < nbElem/2; ++i)
	{
		lft[i] = make_pair(min(a[i], a[nbElem-1-i]), max(a[i], a[nbElem-1-i]));
		rgt[i] = make_pair(min(b[i], b[nbElem-1-i]), max(b[i], b[nbElem-1-i]));
	}
	sort(lft.begin(), lft.end());
	sort(rgt.begin(), rgt.end());
	for (int i(0); i < SZ(lft); ++i)
		if (lft[i] != rgt[i])
			return false;
	if (nbElem%2 and a[nbElem/2] != b[nbElem/2])
		return false;
	return true;
}

int main(void)
{
	int nbTests(1);
	cin >> nbTests;
	for (int i(0); i < nbTests; ++i)
		cout << (solve() ? "yes" : "no") << '\n';
}