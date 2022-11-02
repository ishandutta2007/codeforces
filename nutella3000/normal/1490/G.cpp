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
      
const int inf = 1e15 + 7;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
    	int n, m;
    	cin >> n >> m;
    	vector<int> a(n), b(n);
    	int mx = 0;
    	for(int i = 0;i < n;i++) {
    		cin >> a[i];
    		if (i != 0) a[i] += a[i - 1];
    		mx = max(mx, a[i]);
    		b[i] = a[i];
    		if (i != 0) chkmax(b[i], b[i - 1]);
    	}

    	int sum = a[n - 1];

    	for(int it1 = 0;it1 < m;it1++) {
    		int x;
    		cin >> x;
    		int num = (x - mx);
    		int it = 0;
    		if (num > 0 && sum <= 0) {
    			cout << -1 << " ";
    			continue;
    		}

    		if (num > 0) {
    			it = (num + sum - 1) / sum;
    			x = mx + (num - (num + sum - 1) / sum * sum);
    			it *= n;
    		}
    		if (x == 0) n /= (n - n);
    		//if (x > mx) n /= (n - n);
    		int l = -1, r = n;
    		//cout << it << " " << x << endl;

    		while(r - l > 1) {
    			int mid = (l + r) / 2;
    			if (b[mid] >= x) r = mid;
    			else l = mid;
    		}
    		//if (r == n) n /= (n - n);

    		cout << it + r << " ";
    	}
    	cout << endl;
    }
}