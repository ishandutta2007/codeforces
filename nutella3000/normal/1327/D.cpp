#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;
const int max_n = 2e5 + 1;
int n, p[max_n], c[max_n];

bool used[max_n];


int solve(vector<int> a) {
	for(int step = 1;step <= a.size();step++) {
		if (a.size() % step != 0) continue;
		for(int start = 0;start < step;start++) {
			bool bad = false;
			for(int i = start;i < a.size();i += step) if (a[i] != a[start]) bad = true;
			if (!bad) return step;
		}
	}
}



void solve() {
	cin >> n;

	for(int i = 0;i < n;i++) used[i] = false;

	for(int i = 0;i < n;i++) {
		cin >> p[i];
		p[i]--;
	}
	for(int i = 0;i < n;i++) cin >> c[i];

	int res = inf;
	for(int i = 0;i < n;i++) {
		if (used[i]) continue;
		vector<int> cyc;
		int v = i;
		while(!used[v]) {
			used[v] = true;
			cyc.emplace_back(c[v]);
			v = p[v];
		}

		res = min(res, solve(cyc));
	}

	cout << res << '\n';
}



signed main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 	cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) solve();
}