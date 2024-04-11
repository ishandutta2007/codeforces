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
const int max_n = 15;

int n, y = 0;
vector<int> b;
int fact[max_n];


void req() {
	int x;
	cin >> x;
	y += x;

	x = y;

	set<int> c;
	for(int i = n - 1;i >= 0 && n - 1 - i < max_n;i--)
		c.emplace(i + 1);
	
	for(int i = max(0ll, n - max_n);i < n;i++) {
		int num = n - 1 - i;
		for(auto j : c) {
			if (x >= fact[num]) x -= fact[num];
			else {
				b[i] = j + (i == 0 ? 0 : b[i - 1]);
				c.erase(j);
				break;
			}
		}
	}
}

void solve() {
	fact[0] = 1;
	for(int i = 1;i < max_n;i++)
		fact[i] = fact[i - 1] * i;

	int q;
	cin >> n >> q;
	b.resize(n);
	for(int i = 0;i < n;i++)
		b[i] = i + 1 + (i == 0 ? 0 : b[i - 1]);

	for(int it = 0;it < q;it++) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r;
			cin >> l >> r;
			--r; --l;
			cout << b[r] - (l == 0 ? 0 : b[l - 1]) << endl;
		}else {
			req();
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