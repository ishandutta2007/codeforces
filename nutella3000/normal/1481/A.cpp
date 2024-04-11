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
const int max_n = 1e5 + 3;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
    	int x, y;
    	string s;
    	cin >> x >> y >> s;
    	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    	for(char i : s) {
    		if (i == 'R') x2++;
    		if (i == 'L') x1--;
    		if (i == 'U') y2++;
    		if (i == 'D') y1--;
    	}
    	if (x <= x2 && x >= x1 && y <= y2 && y >= y1) cout << "YES" << endl;
    	else cout << "NO" << endl;
    }
}