#include <bits/stdc++.h>

using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
 
#define int long long
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

const int inf = 1e15;

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    //cout.precision(3);

    int t;
    cin >> t;
    while(t--) {
    	int n, k;
    	cin >> n >> k;
    	vector<int> a(n);
    	for(int i = 0;i < n;i++)
    		cin >> a[i];

    	int res = inf;
    	for(int c = 0;c <= 100;c++) {
    		int new_res = 0;
    		for(int i = 0;i < n;i++) {
    			if (a[i] != c) {
    				new_res++;
    				i += k - 1;
    			}
    		}
    		chkmin(res, new_res);
    	}

    	cout << res << endl;
    }
}