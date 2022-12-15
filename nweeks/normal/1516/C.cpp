#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXV = 2000 * 100 + 1;

bool can[MAXV];

signed main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbElem;
	cin >> nbElem;
	vector<int> arr(nbElem);
	for (auto &v : arr) cin >> v;

	int plusGrande = 1 << 20;
	for (int i(0); i < nbElem; ++i)
		plusGrande = gcd(plusGrande, arr[i]);
	for (auto &v : arr)
		v /= plusGrande;

	int sum(0);
	for (auto v : arr) sum += v;

	if (sum % 2)
	{
		cout << 0 << endl;
		return 0;
	}
	can[0] = true;
	for (auto v : arr)
		for (int i(MAXV-1); i >= v; --i)
			can[i] = can[i] or can[i-v];
	if (can[sum/2])
	{
		cout << 1 << endl;
		for (int i(0); i < nbElem; ++i)
			if (arr[i]%2)
			{
				cout << i+1 << endl;
				return 0;
			}
	}
	cout << 0 << endl;
}