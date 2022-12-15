#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

const int MAXP = 23;

int representant[1<<MAXP];

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbElem;
	cin >> nbElem;
	int compMask(0);
	for (int i(0); i < MAXP; ++i)
		compMask |= (1<<i);
	for (int i(0); i < (1<<MAXP); ++i)
		representant[i] = -1;	
	vector<int> arr(nbElem);
	for (auto &v : arr)
	{
		cin >> v;
		representant[v] = v;
	}
	for (int i(0); i < MAXP; ++i)
		for (int mask(0); mask < (1<<MAXP); ++mask)
			if (mask & (1<<i))
				representant[mask] = max(representant[mask], representant[mask ^ (1<<i)]);
	for (int i(0); i < nbElem; ++i)
		cout << representant[compMask^arr[i]] << ' ';
	cout << endl;
}