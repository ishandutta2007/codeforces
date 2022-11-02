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

int f(int n, int p, int k) {
	return (n - p + 1 + k - 1) / k;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    //cout.precision(3);

    int t;
    cin >> t;
    while(t--) {
    	int n, p, k, x, y;
    	string s;
    	cin >> n >> p >> k >> s >> x >> y;

    	vector<int> cnt(k);

    	for(int i = 0;i < n;i++) {
    		if (s[i] == '1') cnt[i % k]++;
    	}

    	int res = inf;

    	for(int i = 0;i < n;i++) {
    		int new_res = f(n, i + 1, k) - cnt[i % k];
    		//cout << i + 1 << " " << new_res << " " << cnt[i % k] << endl;
    		if (i >= p - 1) chkmin(res, new_res * x + y * (i - p + 1));
    		if (s[i] == '1') cnt[i % k]--;
    	}

    	cout << res << endl;
    }
}