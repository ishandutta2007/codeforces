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
    	int n;
    	cin >> n;
    	vector<int> c(n), a(n), b(n);
    	for(int i = 0;i < n;i++)
    		cin >> c[i];
    	for(int i = 0;i < n;i++)
    		cin >> a[i];
    	for(int i = 0;i < n;i++)
    		cin >> b[i];

    	int res = 0;
    	int nres = c[0];
    	for(int i = 1;i < n;i++) {


    		int q1 = abs(a[i] - b[i]) + 1;
    		int q2 = q1 - 2;
    		if (i == 1 || a[i] == b[i]) nres = q1;
    		else {
    			nres -= q2;
    			if (nres < q1) {
    				nres = q1;
    			}
    		}
    		nres += c[i];

    		chkmax(res, nres);
    	}
    	chkmax(res, nres);
    	cout << res << endl;
    }
}