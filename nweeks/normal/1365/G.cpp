#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())

using ll = long long;

const int MAXQ = 13;
int nbElem;
vector<int> mask;

ll makeQuery(int hideBit)
{
	vector<int> pos;
	for (int i(0); i < nbElem; ++i)
		if (mask[i] & (1<<hideBit))
			pos.push_back(i+1);
	if (!SZ(pos))
		return 0;
	cout << "? " << SZ(pos) << ' ';
	for (auto  v : pos) cout << v << ' ';
	cout << endl;
	ll ret(0);
	cin >> ret;
	return ret;
}

void solve()
{
	cin >> nbElem;
	mask.resize(nbElem);
	int cur(0);
	for (int i(0); i < nbElem; ++i)
	{
		while (__builtin_popcount(cur) != 6)
			++cur;
		mask[i] = cur++;
	}
	vector<ll> req(MAXQ);
	for (int i(0); i < MAXQ; ++i)
		req[i] = makeQuery(i);
	vector<ll> pass(nbElem);
	for (int i(0); i < nbElem; ++i)
		for (int j(0); j < MAXQ; ++j)
			if (!((1<<j) & mask[i]))
				pass[i] |= req[j];
	cout << "!";
	for (auto v : pass)
		cout << ' ' << v;
	cout << endl;
}

int main(void)
{
	int nbTests(1);
	for (int i(0); i < nbTests; ++i)
		solve();
}