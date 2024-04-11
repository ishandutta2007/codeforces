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


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int n, q;
    cin >> n >> q;
   	vector<int> a(n);
   	int cnt = 0;
   	for(int i = 0;i < n;i++)
   		cin >> a[i], cnt += a[i];

   	for(int it = 0;it < q;it++) {
   		int t, x;
   		cin >> t >> x;
   		if (t == 1) {
   			if (a[x - 1]) cnt--;
   			else cnt++;
   			a[x - 1] = 1 - a[x - 1];
   		}else {
   			cout << (cnt >= x ? 1 : 0) << endl;
   		}
   	}
}