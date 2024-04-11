#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;
const int max_n = 2e5 + 5;
int n, m, in[max_n], out[max_n], parent[max_n], timer = 0;
vector<int> gr[max_n];

void build(int v, int pr) {
	parent[v] = pr;
	in[v] = timer++;
	for(int i : gr[v]) {
		if (i == pr) continue;
		build(i, v);
	}
	out[v] = timer++;
}


void scan() {
	cin >> n >> m;
	for(int i = 0;i < n - 1;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		gr[v1].emplace_back(v2);
		gr[v2].emplace_back(v1);
	}

	build(0, 0);
}


bool solve(vector<int> b) {
	sort(b.begin(), b.end(), [](int v1, int v2) {return in[v1] < in[v2];});

	for(int i = 1;i < b.size();i++) {
		if (out[b[i]] > out[b[i - 1]]) return false;
	}
	return true;
}

void solve() {
	scan();
	for(int it = 0;it < m;it++) {
		int k;
		cin >> k;
		vector<int> v;
		for(int i = 0;i < k;i++) {
			int q;
			cin >> q;
			v.emplace_back(parent[q - 1]);
		}
		if (solve(v)) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}



signed main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 	cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}