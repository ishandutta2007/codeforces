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

int f(int l, int r, vector<int>& x) {
	return abs(x[0] - l) + abs(x[1] - l) + abs(x[2] - r) + abs(x[3] - r);	
}

int f(int d, vector<int>& x) {
	int res = inf;
	for(int i : x) {
		chkmin(res, min(f(i, i + d, x), f(i - d, i, x)));
	}
	return res;
}

int bit(int a, int b) {
	return (a >> b) & 1;
}

void solve() {
	vector<int> x(4), y(4);
	for(int i = 0;i < 4;i++)
		cin >> x[i] >> y[i];
	
	set<int> a;
	for(int i = 0;i < 4;i++) {
		for(int j = i + 1;j < 4;j++)
			a.emplace(abs(x[i] - x[j])), a.emplace(abs(y[i] - y[j]));
	}

	vector<int> p(4);
	iota(all(p), 0);
	int res = inf;

	for(int m1 = 0;m1 < 16;m1++) {
		if (__builtin_popcount(m1) != 2) continue;
		for(int m2 = 0;m2 < 16;m2++) {
			if (__builtin_popcount(m2) != 2) continue;
			bool bad = false;
			for(int i = 0;i < 4;i++) {
				for(int j = i + 1;j < 4;j++) {
					if (bit(m1, i) == bit(m1, j) && bit(m2, i) == bit(m2, j)) bad = true;
				}
			}
			if (bad) continue;
			vector<int> new_x(4), new_y(4);
			int t[]{0, 2};
			for(int i = 0;i < 4;i++)
				new_x[t[bit(m1, i)]++] = x[i];
			t[0] = 0, t[1] = 2;
			for(int i = 0;i < 4;i++)
				new_y[t[bit(m2, i)]++] = y[i];

			for(int d : a) {
				chkmin(res, f(d, new_x) + f(d, new_y));
			}
		}
	}

	cout << res << endl;
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