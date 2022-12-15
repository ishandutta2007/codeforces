#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll nbElem;
	cin >> nbElem;
	vector<ll> arr(nbElem);
	for (auto &v : arr)
		cin >> v;
	if (nbElem == 1)
	{
		cout << 1 << ' ' << 1 << endl << -arr[0] << endl; 
		for (int i(0); i < 2; ++i)
			cout << 1 << ' ' << 1 << endl << 0 << endl;
		return 0;
	}
	cout << 1 << ' ' << nbElem << endl;
	for (auto v : arr)
		cout << -nbElem * v << ' ';
	cout << endl;
	cout << 1 << ' ' << nbElem - 1 << endl;
	for (int i(0); i < nbElem-1; ++i)
		cout << arr[i] * (nbElem-1) << ' ';
	cout << endl;
	cout << nbElem << ' ' << nbElem << endl;
	cout << (nbElem -1) * arr[nbElem-1] << endl;
}