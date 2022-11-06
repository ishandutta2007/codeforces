#include <bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mp make_pair

using namespace std;

ll mod = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_HOME
		I_O;
	#else
	#define print(...) 0
	#endif
	ll n, a, b, k;
	cin >> n >> a >> b >> k;
	std::vector<ll> res;
	if(a < b)
		res.resize(b, 0);
	else
		res.resize(n - b + 1, 0);
	a = (a > b) ? a - b: b - a;
	std::vector<ll> pre(res.size() + 1, 0);
	n = res.size();
	//round 0
	res[a] = 1;
	pre[0] += res[a];
	pre[a - 1] -= res[a];
	pre[a] += res[a];
	pre[min(n - 1, 2 * a - 1)] -= res[a];
	//round.next
	for (int o = 0; o < k; ++o)
	{
		res[0] = 0;
		for (int i = 1; i < n; ++i) {
			res[i] = res[i-1] + pre[i-1];
			if(res[i] > mod)
				res[i] -= mod;
		}
		fill(pre.begin(), pre.end(), 0);
		for (int i = 1; i < n; ++i)
		{
			pre[0] += res[i];
			if(pre[0] > mod)
				pre[0] -= mod;
			pre[i - 1] -= res[i];
			if(pre[i - 1] < 0)
				pre[i - 1] += mod;
			pre[i] += res[i];
			if(pre[i] > mod)
				pre[i] -= mod;
			pre[min((int)n - 1, 2 * i - 1)] -= res[i];
			if(pre[min((int)n - 1, 2 * i - 1)] < 0)
				pre[min((int)n - 1, 2 * i - 1)] += mod;
		}
	}
	ll result = 0;
	for (int i = 0; i < n; ++i)
		result += res[i];
	cout << (result % mod);
}