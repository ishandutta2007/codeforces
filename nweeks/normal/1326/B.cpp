#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	vector<ll> b(n);
	for (auto &v : b)
		cin >> v;

	ll x(0);
	for (int i(0); i < n; ++i)
	{
		ll a = b[i] + x;
		cout << a << ' ';
		x = max(x, a);
	}
	cout << endl;
}