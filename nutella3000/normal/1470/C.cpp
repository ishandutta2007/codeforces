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
       
const int inf = 2e9 + 7;

void solve() {
	int n, k;
	cin >> n >> k;

	for(int i = 0, j = 0;i <= n + j + 5;j++, i += j) {
		if (j == (n - 1) / 2) j--;
		cout << "? " << i % n + 1 << endl;
		int num;
		cin >> num;
		if (num > k) {
			while(true) {
				--i;
				cout << "? " << i % n + 1 << endl;
				cin >> num;
				if (num == k) {
					cout << "! " << i % n + 1 << endl;
					return;
				}
			}
		}
	}
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}