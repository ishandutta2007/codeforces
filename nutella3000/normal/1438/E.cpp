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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0;i < n;i++)
		cin >> a[i];


	auto comp = [](pii v1, pii v2) {
		return mp(-v1.fi, v1.se) < mp(-v2.fi, v2.se);
	};

	set<pii, decltype(comp)> s(comp);

	vector<pii> seg;

	int global = 0;
	for(int i = n - 1;i > 0;i--) {
		global += a[i];

		for(auto j : s) {
			if (j.fi - global + a[i - 1] < 0) break;
			seg.emplace_back(i - 1, j.se);	
		}
		s.emplace(a[i] + global, i);
	}


	vector<int> b(n);
	b[0] = a[0];
	for(int i = 1;i < n;i++)
		b[i] = a[i] + b[i - 1];

	int res = 0;
	for(pii i : seg) {
		int r1 = b[i.se - 1] - b[i.fi];
		int r2 = a[i.fi] ^ a[i.se];
		if (r1 == r2) res++;
	}
	cout << res << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}