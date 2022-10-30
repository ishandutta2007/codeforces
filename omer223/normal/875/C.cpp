
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int sz = 1e5 + 6;
vector<int> adj[sz];
bitset<sz> vis, no;
bool bad = 0;

void dfs(int src) {
	vis[src] = 1;
	for (int x : adj[src]) {
		if (!vis[x])dfs(x);
	}
}


int main() {
	fast;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n);
	foru(i, 0, n) {
		int l;
		cin >> l;
		a[i].resize(l);
		foru(j, 0, l)cin >> a[i][j];
	}
	vector<bool> cap(m + 1, 0), nocap(m + 1, 0);
	vector<int> need;
	foru(i, 0, n - 1) {
		int l1 = a[i].size(), l2 = a[i + 1].size();
		bool founddiff = 0;
		foru(j, 0, min(l1,l2)) {
			if (a[i][j] != a[i + 1][j]) {
				founddiff = 1;
				if (a[i][j] < a[i + 1][j]) {
					adj[a[i + 1][j]].push_back(a[i][j]);
				}
				else {
					need.push_back(a[i][j]);
					no[a[i + 1][j]] = 1;
				}
				break;
			}
		}
		if (!founddiff && l1 > l2)bad = 1;
	}
	if (bad) {
		cout << "No\n";
		return 0;
	}
	else {
		for (int x : need) {
			dfs(x);
		}
		if ((vis & no).any()) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	cout << vis.count() << '\n';
	foru(i, 0, m + 1) {
		if (vis[i])cout << i << ' ';
	}
	return 0;
}