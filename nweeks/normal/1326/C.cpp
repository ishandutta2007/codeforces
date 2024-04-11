#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

const ll MOD = 998244353;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, k;
	cin >> n >> k;

	vector<int> p(n);
	for (auto &v : p)
		cin >> v;

	ll ways(0);
	ll ans(0);
	for (int i(0); i < k; ++i)
		ans += n-i;

	vector<int> pos;
	pos.reserve(k);
	for (int i(0); i < n; ++i)
		if (p[i] + k > n)
			pos.push_back(i);
	sort(pos.begin(), pos.end());
	ways = 1;
	for (int i(0); i < k-1; ++i)
	{
		ways *= pos[i+1] - pos[i];
		ways %= MOD;
	}
	cout << ans << ' ' << ways << endl;

}