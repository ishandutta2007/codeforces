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
		string s;
		cin >> s;
		bool good = false;
		for(int m = 0;m < 8;m++) {
			int c = 0;
			bool bad = false;
			for(int i = 0;i < sz(s);i++) {
				int j = s[i] - 'A';
				if ((m >> j) & 1) c++;
				else c--;
				if (c < 0) bad = true;
			}
			if (c != 0) bad = true;
			if (!bad) good = true;
		}

		if (good) cout << "YES" << endl;
		else cout << "NO" << endl;
	}    
}