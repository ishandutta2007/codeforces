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

	int t;
	cin >> t;
	while(t--) {
		int n, a[4];
		cin >> n >> a[0] >> a[1] >> a[2] >> a[3];

		bool good = false;

		for(int m = 0;m < 16;m++) {
			vector<int> b(4);
			for(int i = 0;i < 4;i++) b[i] = a[i];
				
			for(int i = 0;i < 4;i++) {
				if ((m >> i) & 1) {
					b[i]--;
					b[(i + 1) % 4]--;
				}
			}

			bool bad = false;
			for(int i : b)
				if (i < 0 || i > n - 2) bad = true;
			if (!bad) good = true;
		}

		cout << (good ? "YES" : "NO") << endl;
	}    
}