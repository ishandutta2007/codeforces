#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int sz = 5e5;
int a[sz], ans[sz], into[sz];
bitset<sz> vis, tvis, iscyc;
vector<int> radj[sz];
int pts = 0;
int n;

void assign(int src) {
	vis[src] = 1;
	bool f = 0;
	for (int x : radj[src]) {
		assign(x);
		if (!f) {
			ans[x] = src;
			into[src] = x;
			f = 1;
			pts++;
		}
	}
}

void foo(int i) {
	stack<int> stk;
	while (!tvis[i]) {
		stk.push(i);
		tvis[i] = 1;
		i = a[i];
	}
	vector<int> cyc;
	while (stk.top() != i) {
		iscyc[stk.top()] = 1;
		cyc.push_back(stk.top()); stk.pop();
	}
	cyc.push_back(i);
	iscyc[i] = 1;
	for (int x : cyc) {
		if (radj[x].size() > 1) {
			for (int y : radj[x]) {
				if (!iscyc[y]) {
					assign(y);
				}
			}
		}
		if (!iscyc[radj[x][0]] || radj[x].size() == 1) {
			ans[radj[x][0]] = x;
			into[x] = radj[x][0]; //CHECK
		}
		else {
			ans[radj[x][1]] = x;
			into[x] = radj[x][1]; //CHECK
		}
		pts++;
		vis[x] = 1;
	}
}

void finish() {
	vector<pii> v;
	foru(i, 0, n) {
		if (into[i] == -1) {
			int nxt = i;
			while (ans[nxt] != -1)nxt = ans[nxt];
			v.push_back({ i,nxt });
		}
	}
	int m = v.size();
	foru(i, 0, m) {
		ans[v[i].second] = v[(i+1)%m].first;
		into[v[(i+1)%m].first] = v[i].second;
	}
}

void solve() {
	cin >> n;
	pts = 0;
	foru(i, 0, n)cin >> a[i], ans[i] = -1, into[i] = -1, a[i]--, vis[i] = 0, tvis[i] = 0, iscyc[i] = 0, radj[i].clear();
	foru(i, 0, n)radj[a[i]].push_back(i);
	foru(i, 0, n)if (!vis[i])foo(i);
	finish();
	cout << pts << '\n';
	foru(i, 0, n)cout << ans[i] + 1 << ' ';
	cout << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}