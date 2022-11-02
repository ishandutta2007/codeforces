#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
 
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double

const int inf = 1e9 + 7;
const int mod = 1e9 + 7;

int binpow(int a, int b) {
	int res = 1;
	for(;b > 0;b /= 2, a = a * a % mod)
		if (b & 1) res = res * a % mod;
	return res;
}

int cnk(int n, int k) {
	int res = 1;
	for(int i = k + 1;i <= n;i++)
		res = res * i % mod;
	for(int i = 1;i <= n - k;i++) {
		res = res * binpow(i, mod - 2) % mod;
	}
	return res;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int max_n = 2e5 + 3;
    vector<vector<int>> del(max_n);

    for(int i = 1;i < max_n;i++) {
    	for(int j = 1;j * j <= i;j++) {
    		if (i % j == 0) {
    			if (j != i) del[i].emplace_back(j);
    			if (j * j != i && j != 1) del[i].emplace_back(i / j);
    		}
    	}
    }
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	vector<int> dp(max_n);
    	vector<int> a(max_n);
    	for(int i = 0;i < n;i++) {
    		int v;
    		cin >> v;
    		a[v]++;
    	}

    	int res = 0;

    	for(int i = 0;i < max_n;i++) {
    		if (a[i] == 0) continue;
    		dp[i] = a[i];

    		for(int j : del[i])
    			chkmax(dp[i], dp[j] + a[i]);

    		//cout << i << " " << dp[i] << endl;
    		chkmax(res, dp[i]);
    	}

    	cout << n - res << endl;
   }
}