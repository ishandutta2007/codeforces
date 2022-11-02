#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;
const int max_n = 2e5 + 1;
int mod = 998244353;
int n, p[max_n];

void solve() {
	cin >> n;
	p[0] = 1;
	for(int i = 1;i < max_n;i++) p[i] = (p[i - 1] * 10) % mod;

	for(int i = 1;i <n;i++) {
		int res = (int)2 * 9 * 10 * p[n - i - 1] % mod;
		if (i < n - 1) res = (res + 9 * 9 * 10 * p[n - i - 2] * (n - i - 1)) % mod;
		cout << res << " ";
	}
	cout << 10;

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