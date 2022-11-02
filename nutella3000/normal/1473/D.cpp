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
    	int n, m;
    	string t;
    	cin >> n >> m >> t;
    	n += 2;
    	t = "?" + t + "?";
    	vector<int> l_u(n), l_d(n), r_u(n + 1), r_d(n + 1), sum(n + 1);

    	int mx = 0, mn = 0, s = 0;
    	for(int i = 0;i < n;i++) {
    		if (t[i] == '+') s++;
    		else if (t[i] == '-') s--;
    		sum[i] = s;
    		mx = max(mx, s);
    		mn = min(mn, s);
    		l_u[i] = mx;
    		l_d[i] = mn;
    	}

    	mx = 0, mn = 0, s = 0;

    	for(int i = n - 1;i >= 0;i--) {
    		if (t[i] == '+') s--;
    		else if (t[i] == '-') s++;
    		mx = max(mx, s);
    		mn = min(mn, s);
    		r_u[i] = mx - s;
    		r_d[i] = mn - s;
    	}

    	/*for(int i = 0;i < n;i++) {
    		cout << l_d[i] << " " << l_u[i] << " " << r_d[i] << " " << r_u[i] << endl;
    	}*/

    	for(int it = 0;it < m;it++) {
    		int l, r;
    		cin >> l >> r;
    		l -= 1; r++;
    		// l_u[l] l_d[l]
    		// r_u[r] + s   r_d[r] + s

    		//cout << l << " " << r << " " << sum[l] << endl;
    		mx = max(l_u[l], r_u[r] + sum[l]);
    		mn = min(l_d[l], r_d[r] + sum[l]);

    		cout << mx - mn + 1 << endl;
    	}
    }
}