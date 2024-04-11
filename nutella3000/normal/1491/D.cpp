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

bool solve() {
	int v, to;
	cin >> v >> to;
	vector<int> a, b;
	for(int i = 29;i >= 0;i--) {
		if ((v >> i) & 1) a.emplace_back(i);
		if ((to >> i) & 1) b.emplace_back(i);
	}

	if (sz(b) > sz(a)) return false;
	while(sz(b) && a[0] == b[0]) {
		a.erase(a.begin());
		b.erase(b.begin());
	}
	if (sz(a) == 0) return true;
	if (sz(b) == 0) return false;
	if (a[0] > b[0]) return false;

	int k = sz(b) - 1;
	for(int i = 1;i < sz(b);i++) {
		int n1 = b[i];
		int n2 = a[sz(a) - k + i - 1];
		if (n2 > n1) return false;
	}
	return true;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
    	if (!solve()) cout << "NO" << endl;
    	else cout << "YES" << endl;
    }
}