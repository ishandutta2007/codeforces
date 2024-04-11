#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e5;
vector<int> adj[sz];

bool dfs(int x) {
	int cnt = 0;
	for (int k : adj[x]) {
		if (adj[k].empty())cnt++;
		else if (!dfs(k))return false;
	}
	return (cnt >= 3);
}

int main() {
	int n, a;
	cin >> n;
	foru(i, 1, n) {
		cin >> a; a--;
		adj[a].pb(i);
	}
	cout << (dfs(0) ? "YES" : "NO") << endl;
	return 0;
}