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
const int max_n = 2e5 + 3;


int f(vector<int> a, vector<int> b) {
	int n = sz(a), m = sz(b);
	a.emplace_back(inf);
	b.emplace_back(inf);

	int res = 0;

	int id = n - 1;
	int le = m - 1;
	int rest = 0;

	for(int i = m - 1;i >= 0;i--) {
		while(id >= 0 && a[id] > b[i]) id--;

		while(le > 0 && b[i] - b[le - 1] + 1 <= id + 1) le--;
		while(b[i] - b[le] + 1 > id + 1) le++;
		int nre = (i - le + 1) + rest;

		chkmax(res, nre);

		if (*lower_bound(all(a), b[i]) == b[i]) rest++;
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a1, a2, b1, b2;
	for(int i = 0;i < n;i++) {
		int v;
		cin >> v;
		if (v < 0) a1.emplace_back(-v);
		else a2.emplace_back(v);
	}
	for(int i = 0;i < m;i++) {
		int v;
		cin >> v;
		if (v < 0) b1.emplace_back(-v);
		else b2.emplace_back(v);
	}
	reverse(all(a1));
	reverse(all(b1));
	int r1 = f(a1, b1);
	int r2 = f(a2, b2);
	cout << r1 + r2 << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    int t;
    cin >> t;
    while(t--) solve();
}