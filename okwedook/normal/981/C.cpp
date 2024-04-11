#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<typename T1> inline void shuffle(T1 &arr) { 
    for (int i = -arr.size(); i < arr.size(); ++i) {
        int f = ((rand() << 16) + rand()) % arr.size(), s = ((rand() << 16) + rand()) % arr.size();
        swap(arr[f], arr[s]);
    }
}
template<typename T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;
graph G;
vector<bool> used;
vector<int> ans;

void dfs(int v) {
	ans[v] = v;
	used[v] = true;
	for (auto i : G[v])
		if (!used[i]) {
			dfs(i);
			ans[v] = ans[i];
		}
}

int main() {
	FAST;
	int n;
	cin >> n;
	G = graph(n);
	used = vector<bool>(n);
	ans = vector<int>(n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		G[u].pb(v);
		G[v].pb(u);
	}
	int ind = 0, cnt = 0; 
	for (int i = 0; i < n; ++i) {
		if (G[i].size() > 1) ind = i;
		if (G[i].size() > 2) ++cnt;
	}
	if (cnt > 1) {
		cout << "No";
		return 0;
	}
	if (cnt == 1)
		for (int i = 0; i < n; ++i)
			if (G[i].size() > 2) ind = i;
	dfs(ind);
	cout << "Yes\n";
	cout << G[ind].size() << '\n';
	for (auto i : G[ind]) cout << ind + 1 << ' ' << ans[i] + 1 << '\n';
    return 0;
}