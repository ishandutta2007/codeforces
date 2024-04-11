#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;
const int max_n = 14;
int n;
bool gr[max_n][max_n];
vector<int> dp[(1 << max_n)][max_n];

void scan() {
	cin >> n;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			char c;
			cin >> c;
			gr[i][j] = c - '0';
		}
	}
}

void get(int mask, int last, int mask_con) {
	for(int prev = 0;prev < n;prev++) {
		if (prev == last || !(mask & (1 << prev)) || gr[prev][last] != (mask_con & 1)) continue;
		dp[mask][last][mask_con] += dp[mask - (1 << last)][prev][mask_con >> 1];
	}
}

void solve() {
	scan();
	for(int mask = 1;mask < (1 << n);mask++) {
		int sz = (1 << (__builtin_popcount(mask) - 1));

		for(int mask_con = 0;mask_con < sz;mask_con++) {
			for(int last = 0;last < n;last++) {
				if (!(mask & (1 << last))) continue;
				dp[mask][last].resize(sz, 0);
				if (sz == 1) {
					dp[mask][last][0] = 1;
				}else {
					get(mask, last, mask_con);
				}
			}
		}
	}

	vector<int> res((1 << n), 0);
	for(int last = 0;last < n;last++) {
		for(int i = 0;i < (1 << (n - 1));i++) res[i] += dp[(1 << n) - 1][last][i];
	}
	
	for(int i = 0;i < (1 << (n - 1));i++) cout << res[i] << " ";
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