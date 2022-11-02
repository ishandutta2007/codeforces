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
    	string s, t;
    	cin >> s >> t;
    	string res;
    	bool good = false;
    	for(int i = 0;i < 30;i++) {
    		res += s;
    		bool bad = false;
    		for(int j = 0;j < sz(res);j++) {
    			if (res[j] != t[j % sz(t)]) bad = true;
    		}
    		if (sz(res) % sz(t) != 0) bad = true;
    		if (!bad) {
    			cout << res << endl;
    			good = true;
    			break; 
    		}
    	}
    	if (!good) cout << -1 << endl;
    }
}