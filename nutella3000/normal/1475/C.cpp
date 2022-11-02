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
const int max_n = 2e5 + 3;

vector<int> g1[max_n], g2[max_n];


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) {
    	int n1, n2, k;
    	cin >> n1 >> n2 >> k;
    	vector<int> a(k), b(k);
    	for(int i = 0;i < k;i++)
    		cin >> a[i];
    	for(int i = 0;i < k;i++)
    		cin >> b[i];

    	for(int i = 0;i < k;i++) {
    		g1[a[i]].emplace_back(b[i]);
    		g2[b[i]].emplace_back(a[i]);
    	}

    	int res = 0;
    	for(int i = 0;i < k;i++) {
    		res += k - 1 - (sz(g1[a[i]]) + sz(g2[b[i]]) - 2);
    	}
    	cout << res / 2 << endl;

    	for(int i = 0;i <= max(n1, n2);i++) {
    		g1[i].clear();
    		g2[i].clear();
    	}
   }
}