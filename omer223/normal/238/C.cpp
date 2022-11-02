#define _CRT_SECURE_NO_WARNINGS
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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef long double ld;
typedef pair <ld, ld> pld;

const int sz = 3e3;
int n;
vector<pii> adj[sz];
int dpfrom[sz], dp[sz], f[sz], fdir[sz], dpc[sz];
vector<int> bads;

void input() {
	cin >> n;
	foru(i, 0, n - 1) {
		int a, b;
		cin >> a >> b; a--; b--;
		adj[a].pb({ b,1 });
		adj[b].pb({ a,0 });
	}
}


void dfs1(int src, int prv) {
	f[src] = prv;
	for (auto x : adj[src]) {
		if (x.first != prv) {
			dfs1(x.first, src);
			fdir[x.first] = x.second;
		}
	}
}

void dfs2(int src, int prv) {
	for (auto x : adj[src]){
		if (x.first == prv)continue;
		else if (x.second == 0)bads.pb(x.first);
		else dfs2(x.first, src);
	}
}

void dfs3(int src) {
	for (auto x : adj[src]) {
		if (x.first == f[src])continue;
		else {
			dfs3(x.first);
			dpfrom[src] += dpfrom[x.first];
			if (x.second == 0)dpfrom[src]++;
		}
	}
	dp[src] = dpfrom[src];
	for (auto x : adj[src]) {
		if (x.first == f[src])continue;
		else {
			int option = fdir[x.first] + dp[x.first] + (dpfrom[src] - dpfrom[x.first] - (x.second == 0));
			dp[src] = min(dp[src], option);
		}
	}
	dpc[src] = dp[src];
	for (auto x : adj[src]) {
		if (x.first == f[src])continue;
		else {
			int option1 = (dpfrom[src] - dpfrom[x.first] - (x.second == 0)) + dp[x.first];
			dpc[src] = min(dpc[src], option1);
			int option2 = (dpfrom[src] - dpfrom[x.first]) + dpc[x.first];
			dpc[src] = min(dpc[src], option2);
		}
	}
}

int main() {
	fast;
	input();
	int bst = n - 1;
	foru(i, 0, n) {
		foru(j, 0, n) {
			f[j] = -1;
			dp[j] = 0;
			dpfrom[j] = 0;
			dpc[j] = 0;
		}
		bads.clear();
		dfs1(i, -1);
		dfs2(i, -1);
		int badSize = bads.size(), crsm = 0;
		for (int x : bads) {
			dfs3(x);
			crsm += (dpfrom[x] + 1);
		}
		for (int x : bads) {
			bst = min(bst, crsm - dpfrom[x] - 1 + min(dpc[x] + 1, dp[x]));
		}
	}
	cout << bst << '\n';
	return 0;
}