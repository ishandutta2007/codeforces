#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
using namespace std;

void debug(string names) {
	cout << '\n';
}
template<typename A1, typename... A2>
void debug(string names, A1 par, A2... left) {
	int pos = 0;
	for (; pos < names.size() && names[pos] != ' ' && names[pos] != ','; pos++)
		cout << names[pos];
	cout << ": " << par << "  ";
	while (pos < names.size() && (names[pos] == ' ' || names[pos] == ',')) {
		pos++;
	}
	names.erase(names.begin(), names.begin() + pos);
	debug(names, left...);
}

ll n, s;
int c[100005];
int par[100005], nxt = 1;
int lim;

void dfs(int v = 1, int prev = -1, int dep = 1) {
	par[v] = prev;
	for (int i = 0; i < lim && c[dep + 1] > 0; i++) {
		c[dep + 1]--;
		nxt++;
		dfs(nxt, v, dep + 1);
	}
}

bool can(ll k) {
	for (int i = 0; i <= n; i++) c[i] = 0;
	c[1] = 1;
	multiset<int> M;
	ll need = s - 1, left = n - 1, mn = 0, nxt = 2;
	for (ll i = 2, add = k; M.size() < left; i++) {
		for (int j = 0; j < add && M.size() < left; j++)
			M.insert(i), mn += i;
		add *= k;
	}
	if (mn > need) return false;
	bool found = false;
	while (!found && M.size()) {
		auto it = M.find(nxt);
		if (it == M.end()) it = prev(M.end());
		if (need - nxt < mn - *it) found = true;
		else {
			c[nxt]++;
			mn -= *it;
			need -= nxt;

			M.erase(it);
			nxt++;
		}
	}
	if (M.size()) {
		int tmp = nxt;
		auto it = prev(M.end());
		while (need - tmp < mn - *it) tmp--;

		c[tmp]++;
		mn -= *it;
		need -= tmp;

		M.erase(it);
		for (auto &i : M) c[i]++;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n >> s;
	if (n * (n + 1) / 2 < s) finish("No");
	if (2 * n - 1 > s) finish("No");
	if (n * (n + 1) / 2 == s) {
		cout << "Yes" << '\n';
		for (int i = 1; i < n; i++) cout << i << " ";
		return 0;
	}
	cout << "Yes" << '\n';
	int lo = 2, hi = n - 1, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (can(mid)) hi = mid;
		else lo = mid + 1;
	}
	can(lo);
	//cout << lo << '\n';
	//for (int i = 1; i <= n; i++) cout << c[i] << " "; cout << '\n';
	lim = lo;
	dfs();
	for (int i = 2; i <= n; i++) cout << par[i] << " "; cout << '\n';
}