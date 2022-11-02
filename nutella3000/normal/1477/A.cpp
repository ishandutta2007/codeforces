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


int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
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
    	vector<int> a(n);
    	int num = 0;
    	for(int i = 0;i < n;i++) {
    		cin >> a[i];
    		if (i > 0) num = gcd(num, a[i] - a[i - 1]);
    	}
    	bool good = false;
    	for(int i = 0;i < n;i++) {
    		if ((a[i] - k) % num == 0) good = true;
    	}
    	cout << (good ? "YES" : "NO") << endl;
    }
}