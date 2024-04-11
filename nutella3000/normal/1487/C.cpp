#include <bits/stdc++.h>
      
using namespace std;
      
      
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
      
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
       
//#define int long long
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
    	vector<vector<int>> a(n, vector<int>(n));
    	int res = 0;
    	for(int it = 0;it < n;it++) {
    		int num = 0;
    		for(int i = it + 1;i < it + 1 + (n - 1) / 2;i++) {
    			num = i % n;
    			a[it][i % n] = 2;
    		}
    		if (n % 2 == 0) {
    			a[it][(num + 1) % n] = 1;
    			res++;
    		}
    	}
    	for(int i = 0;i < n;i++) {
    		for(int j = i + 1;j < n;j++)
    			cout << a[i][j] - 1 << " ";
    	}
    	cout << endl;
    }
}