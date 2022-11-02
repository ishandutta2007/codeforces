#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

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

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
    	int n, d;
    	cin >> n >> d;
    	int mn1 = inf, mn2 = inf;
    	int mx = 0;
    	for(int i  =0;i < n;i++) {
    		int v;
    		cin >> v;
    		mx = max(mx, v);
    		if (v < mn1) {
    			mn2 = mn1;
    			mn1 = v;
    		}else if (v < mn2) {
    			mn2 = v;
    		}
    	}
    	cout << ((mn1 + mn2 <= d || mx <= d) ? "YES" : "NO") << endl;
    }
}