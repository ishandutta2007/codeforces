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
const int max_n = (1 << 17);

struct req {
	int r, col;
	req() {}
	req(int r, int col) : r(r), col(col) {}
};

int n, a[max_n], mx[2 * max_n];
vector<req> b[max_n];

void build() {
	fill(mx, mx + 2 * max_n, inf);
}

void segset(int id, int x, int v = 1, int tl = 0, int tr = max_n - 1) {
	if (tl > id || tr < id) return;
	if (tl == id && tr == id) {
		mx[v] = x;
		return;
	}
	int mid = (tl + tr) / 2;
	segset(id, x, v * 2, tl, mid);
	segset(id, x, v * 2 + 1, mid + 1, tr);
	mx[v] = max(mx[v * 2], mx[v * 2 + 1]);
}

int segget(int r, int v = 1, int tl = 0, int tr = max_n - 1) {
	if (tl > r) return -1;
	if (tr <= r) return mx[v];
	int mid = (tl + tr) / 2;
	return max(segget(r, v * 2, tl, mid), segget(r, v * 2 + 1, mid + 1, tr));
}

void solve() {
	cin >> n;
	vector<int> lst(n + 1, -1);
	for(int i = 0;i < n;i++) {
		cin >> a[i]; a[i]--;
		b[lst[a[i]] + 1].emplace_back(req(i - 1, a[i]));
		lst[a[i]] = i;
	}
	for(int i = 0;i <= n;i++)
		b[lst[i] + 1].emplace_back(req(n - 1, i));

	build();

	vector<bool> bad(n + 2);

	for(int i = n - 1;i >= 0;i--) {
		segset(a[i], i);
		for(auto r : b[i]) {
			//cout << i << " " << r.r << " " << r.col + 1 << " " << segget(r.col - 1) << endl;
			if (segget(r.col - 1) <= r.r) bad[r.col] = true;
		}
	}
	bad[0] = false;
	for(int i = 0;i < n;i++)
		if (a[i] != 0) bad[0] = true;
	
	for(int i = 0;i <= n + 1;i++) {
		if (!bad[i]) {
			cout << i + 1 << endl;
			return;
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