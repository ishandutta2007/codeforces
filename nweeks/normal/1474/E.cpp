#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;

using ll = long long;

template<typename... Args>
void read(Args&... args)
{
	((cin >> args), ...);
}

template<typename... Args>
void write(Args... args)
{
	((cout << args << " "), ...);
}

template<typename... Args>
void writeln(Args... args)
{
	((cout << args << " "), ...); cout << '\n';
}

void solve(void)
{
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i(0); i < n; ++i) p[i] = i;
	vector<pair<int, int>> swaps;
	ll ret(0);
	for (ll diff(n-1); SZ(swaps) < n-1; --diff)
		for (int k : {0, n-1-(int)diff})
			if (p[k] == k or p[k+diff] == k+diff)
			{
				swaps.emplace_back(k, k+diff);
				swap(p[k], p[k+diff]);
				ret += diff * diff;
			}
	writeln(ret);
	for (auto v : p) write(v+1);
	writeln();
	writeln(SZ(swaps));
	reverse(swaps.begin(), swaps.end());
	for (auto [u, v] : swaps)
	{
		if (p[v] == u)
			writeln(u+1, v+1);
		else
			writeln(v+1, u+1);
		swap(p[u], p[v]);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}