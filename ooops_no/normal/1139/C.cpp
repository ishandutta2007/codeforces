/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
using namespace std;

#define int long long
#define pb push_back
#define ld long double
#define mp make_pair

const int MAXN = 1000001, MOD = 1e9+7;

int cnt = 0;
vector<bool> used(MAXN);
vector<int> g[MAXN];

void dfs(int v) {
	used[v] = 1;
	cnt++;
	for (auto to : g[v]) {
		if (!used[to]) {
			dfs(to);
		}
	}
}
int binpow(int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return (binpow(a, n - 1) * a) % MOD;
	else {
		int b = (binpow(a, n / 2)) % MOD;
		return (b * b) % MOD;
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n, k, s = 0;
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c == 0) {
			g[a].pb(b);
			g[b].pb(a);
		}
	}
	s += binpow(n, k);
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			cnt = 0;
			dfs(i);
			s = (s - binpow(cnt, k) + MOD) % MOD;
		}
	}
	cout << s;
}