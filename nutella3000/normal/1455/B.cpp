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
    	int x;
    	cin >> x;
    	int l = -1, r = 1e5;
    	while(r - l > 1) {
    		int mid = (l + r) / 2;
    		if (mid * (mid + 1) / 2 < x) l = mid;
    		else r = mid;
    	}

    	int res = r + (r * (r + 1) / 2 == x ? 0 : 1);
    	int res1 = l + 2;
    	if (x - l * (l + 1) / 2 <= l - 1) res1 = l + 1;
    	cout << min(res, res1) << endl;
    }
}