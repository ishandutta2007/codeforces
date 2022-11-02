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
        
const int inf = 5e9 + 7;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
    	int n, u, v;
    	cin >> n >> u >> v;
    	vector<int> a(n);
    	for(int i = 0;i < n;i++) 
    		cin >> a[i];
    		
    	int q = 0;
    	for(int i = 1;i < n;i++) {
    		if (abs(a[i] - a[i - 1]) >= 2) q = 2;
    		else if (q != 2 && abs(a[i] - a[i - 1]) == 1) q = 1;
    	}
    	if (q == 2) cout << 0 << endl;
    	else if (q == 1) cout << min(u, v) << endl;
    	else cout << v + min(u, v) << endl;
    }
}