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

    int t;
    cin >> t;
    while(t--) {
    	int n, k;
    	cin >> n >> k;
    	map<int, int> a;
    	for(int i = 0;i < n;i++) {
    		int v;
    		cin >> v;
    		a[v]++;
    	}

    	while(a.rbegin()->se < k) {
    		k -= a.rbegin()->se;
    		a.erase(--a.end());
    	}

    	int num = a.rbegin()->se;

    	cout << cnk(num, k) << endl;
   }
}