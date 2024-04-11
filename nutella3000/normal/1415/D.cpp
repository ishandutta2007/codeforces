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
	return (n - p - 1 + k - 1) / k;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    //cout.precision(3);

    int n;
    cin >> n;
    vector<int> a(n);

    int last_bit = -1, c = 0;
   	bool good = false;
    for(int i = 0;i < n;i++) {
    	cin >> a[i];
    	int now_bit = 0;
    	while((1 << (now_bit + 1)) <= a[i]) now_bit++;
    	if (last_bit == now_bit) {
    		c++;
    		if (c == 3) good = true;
    	}else {
    		last_bit = now_bit;
    		c = 1;
    	}
    }

    if (good) {
    	cout << 1;
    	return 0;
    }

    int res = inf;
    for(int mid = 0;mid < n - 1;mid++) {
    	int a1 = 0;

    	for(int l = mid;l >= 0;l--) {
    		a1 ^= a[l];
    		int a2 = 0;
    		for(int r = mid + 1;r < n;r++) {
    			a2 ^= a[r];

    			if (a2 < a1) chkmin(res, r - mid - 1 + (mid - l));
    		}
    	}

    }

    if (res == inf) cout << -1;
    else cout << res;
}