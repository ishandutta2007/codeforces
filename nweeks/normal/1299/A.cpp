#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 2e5;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i(0); i < n; ++i)
		cin >> a[i];

	vector<int> cnt(32);
	for (int i(0); i < n; ++i)
		for (ll p(0); p < 32; ++p)
			cnt[p] += ((1LL << p) & a[i]) > 0;
	
	for (int i(31); i >= 0; --i)
	{
		if (cnt[i] == 1)
		{
			int which(-1);
			for (int j(0); j < n; ++j)
				if (a[j] & (1LL << i))
					which = j;
			cout << a[which] << ' ';
			for (int k(0); k < n; ++k)
				if (k != which)
					cout << a[k] << ' ';
			cout << endl;
			return 0;
		}
	}
	for (int i(0); i < n; ++i)
		cout << a[i] << ' ';
	cout << endl;
}