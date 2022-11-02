#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int sz = 2e5;
int n, m;
unordered_set<int> fathers;
int f[sz], want[sz];
bitset<sz> vis;
vector<int> adj[sz];
vector<int> ans;
bool bad = 0;
set<pii, greater<pii>> mySet;

void input() {
	cin >> n >> m;
	foru(i, 0, n)f[i] = -1;
	foru(i, 0, m) {
		int a, b;
		cin >> a >> b; a--; b--;
		f[b] = a;
		adj[a].pb(b);
	}
	foru(i, 0, n) {
		if (f[i] == -1)fathers.insert(i);
		cin >> want[i];
		want[i]--;
	}
}

void dfs(int src, int dep) {
	if (!vis[want[src]])mySet.insert({ dep,want[src] });
	vis[want[src]] = 1;
	for (auto x : adj[src]) {
		if (x == f[src])continue;
		if (want[x] != want[src]) {
			if (want[x] != x)bad = 1;
		}
		dfs(x, dep + 1);
	}
}

int main() {
	fast;
	input();
	for (int k : fathers) {
		mySet.clear();
		dfs(k, 0);
		if (bad)break;
		for (pii x : mySet)ans.pb(x.second);
	}
	if (!bad) {
		cout << ans.size() << endl;
		for (int k : ans)cout << k + 1 << " ";
		cout << endl;
	}
	else cout << -1 << endl;
	return 0;
}