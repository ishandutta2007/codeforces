#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())

using ll = long long;

void solve()
{
	int len;
	cin >> len;
	string a, b;
	cin >> a >> b;
	vector<int> ops;
	for (int i(len-1); i >= 0; --i)
	{
		if (a[0] == b[i])
		{
			a[0] = '0' + ('1' - a[i]);
			ops.push_back(1);
		}
		ops.push_back(i+1);
		for (int j(0); i-j >= j; ++j)
		{
			char c = a[j], d =  a[i-j];
			a[j] = '0' + ('1' - d);
			a[i-j] = '0' + ('1' - c);
		}
	}

	cout << SZ(ops) << ' ';
	for (auto v : ops)
		cout << v << ' ';
	cout << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nbTests(1);
	cin >> nbTests;
	for (int i(0); i < nbTests; ++i)
		solve();
}