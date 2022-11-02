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

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	vector<int> b(n);
    	for(int i = 0;i < n;i++)
    		cin >> b[i];

    	map<int, int> c;
    	c[0] = -1;

    	vector<int> p(n), r(n);

    	int num = 0;
    	int q = 0;
    	for(int i = 0;i < n;i++) {
    		num += b[i];
    		if (c.count(num)) {
    			int w = c[num];
    			if (w < 0) {
    				p[i] = 1;
    			}else {
	    			p[i] = r[w];
	    		}
    		}

    		r[i] = binpow(2, i) - q * binpow(2, i) % mod;
    		q += p[i] * binpow(binpow(2, i + 1), mod - 2) % mod;
    		q %= mod;

    		r[i] = (r[i] % mod + mod) % mod;
    		c[num] = i;
    	}
    	cout << r[n - 1] << endl;
    }
}