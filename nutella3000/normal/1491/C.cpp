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
const int max_n = 5e3 + 3;

int par[max_n];

int get(int v) {
	return (par[v] == v ? v : par[v] = get(par[v]));
}

void merge(int v1, int v2) {
	par[get(v1)] = get(v2);
}

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

    	iota(par, par + max_n, 0);

    	vector<int> a(n);
    	for(int i = 0;i < n;i++) {
    		cin >> a[i];
    		if (a[i] == 1) merge(i, i + 1);
    	}

    	int res = 0;
    	while(true) {
    		int i = get(0);
    		if (i >= n) break;

    		if (a[i] > max_n) {
    			res += a[i] - max_n;
    			a[i] = max_n;
    		}
    		//cout << i + 1 << " ";
    		while(i < n) {
    			a[i]--;
    			if (a[i] == 1) merge(i, i + 1);
    			i += a[i] + 1;
    			if (i < n) i = get(i);
    			//cout << i + 1 << " ";
    		}
    		//cout << endl;
    		res++;
    	}

    	cout << res << endl;
    }
}