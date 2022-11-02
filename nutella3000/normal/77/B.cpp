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

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
    	double a, b;
    	cin >> a >> b;
    	if (b == 0) cout << 1 << endl;
    	else if (a == 0) cout << 0.5 << endl;
    	else if (a >= 4 * b) cout << (a * b + 2 * b * b + (a - 4 * b) * b) / (2 * a * b) << endl;
    	else cout << (a * b + a * a / 8) / (2 * a * b) << endl;
    }
}