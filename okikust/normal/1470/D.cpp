#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 300100
#define MOD 1000000007  //998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
int c[N];
vector<int>e[N];

void dfs(int k) {
	int sz = e[k].size();
	if (c[k] == 0) {
		c[k] = 2;
		rep(i, sz) {
			if (c[e[k][i]] == 0)c[e[k][i]] = 1;
		}
	}
	else c[k] = 3;
	rep(i, sz) {
		if (c[e[k][i]] <= 1)dfs(e[k][i]);
	}
	return;
}


int main() {
	vi ans;
	int t, n, m;
	int x, y;
	bool v;
	cin >> t;
	rep(tt, t) {
		cin >> n >> m;
		rep(i, n)c[i] = 0;
		rep(i, m) {
			cin >> x >> y;
			e[x - 1].pb(y - 1);
			e[y - 1].pb(x - 1);
		}
		dfs(0);
		v = true;
		rep(i, n) {
			if (c[i] <= 1)v = false;
			if (c[i] == 2)ans.pb(i + 1);
		}
		x = ans.size();
		if (v) {
			cout << "YES" << endl;
			cout << x << endl;
			rep(i, x - 1)cout << ans[i] << " ";
			cout << ans[x - 1] << endl;
		}
		else cout << "NO" << endl;
		rep(i, n)e[i].clear();
		ans.clear();
	}
	return 0;
}