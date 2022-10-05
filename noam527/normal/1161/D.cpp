#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;
string s;
ll mult = 1;
const ll I = 499122177;
int need[1005] = {};

struct edge {
	int to, w;
	edge() {}
	edge(int tt, int ww) {
		to = tt;
		w = ww;
	}
};

vector<edge> g[1001];
vector<int> a;

void dfs(int v, int c) {
	if (a[v] != -1) return;
	a[v] = c;
	for (const auto &i : g[v])
		dfs(i.to, c ^ i.w);
}

ll calc(int l) {
	if (OO) cout << "calculating for " << l << '\n';
	for (int i = 0; i < n; i++) g[i].clear();
	for (int i = 0; i < l - 1 - i; i++) {
		if (OO) cout << "creating edge " << i << " " << l - 1 - i << " " << 0 << '\n';
		g[i].push_back(edge(l - 1 - i, 0));
		g[l - 1 - i].push_back(edge(i, 0));
	}
	for (int i = 0; i < n; i++) {
		if (need[i]) {
			//if (OO) cout << "making edge " << i << " " << n - 1 - i << " " << need[i] % 2 << '\n';
			g[i].push_back(edge(n - 1 - i, need[i] % 2));
			g[n - 1 - i].push_back(edge(i, need[i] % 2));
		}
	}
	for (auto &i : a) i = -1;
	ll rtn = 1;
	for (int i = l; i < n; i++) {
		if (a[i] == 1) return 0;
		else if (a[i] == -1) {
			dfs(i, 0);
		}
	}
	if (a[0] == -1) rtn = rtn * I % md;
	if (a[0] == 0 || a[l - 1] == 0) return 0;
	for (int i = 0; i < l; i++) {
		if (a[i] == -1) {
			rtn = (rtn * 2) % md;
			dfs(i, 0);
		}
	}
	
	for (int i = 0; i < l; i++) {
		for (const auto &j : g[i])
			if ((a[i] ^ a[j.to]) != j.w) return 0;
	}
	
	/*
	for (int i = 0; i < n; i++) {
		if (need[i]) {
			if ((need[i] % 2) != (a[i] ^ a[n - 1 - i])) return 0;
		}
	}
	for (int i = 0; i < l; i++)
		if (a[i] != a[l - 1 - i]) return 0;
		*/
	if (OO) {
		cout << "answer is " << rtn << '\n';
		cout << "for edges:\n";
		for (int i = 0; i < l; i++)
			for (const auto &j : g[i])
				cout << i << " " << j.to << ", " << j.w << '\n';
	}
	return rtn;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	reverse(s.begin(), s.end());
	n = s.size();
	if (OO) {
		cout << "s: " << s << '\n';
	}
	if (s[0] == '1') finish(0);
	for (int i = 0; i <= n - 1 - i; i++) {
		if (s[i] == '?' && s[n - 1 - i] == '?') mult = mult * 2 % md;
		else if (s[i] != '?' && s[n - 1 - i] != '?') {
			if (s[i] == s[n - 1 - i]) need[i] = need[n - 1 - i] = 2;
			else need[i] = need[n - 1 - i] = 1;
		}
	}
	if (OO) {
		cout << "need: ";
		for (int i = 0; i < n; i++) cout << need[i] << " "; cout << '\n';
	}
	a.resize(n);
	ll ans = 0;
	for (int i = 1; i < n; i++)
		ans = (ans + calc(i)) % md;
	ans = (ans * mult) % md;
	finish(ans);
}