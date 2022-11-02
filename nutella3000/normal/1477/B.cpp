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
const int max_n = 3e5 + 3;

int n;
int cnt[max_n * 2];

void push(int v, int l, int r) {
	if (cnt[v] == 0) cnt[v * 2] = cnt[v * 2 + 1] = 0;
	int m = (l + r) / 2;
	if (cnt[v] == r - l + 1) {
		cnt[v * 2] = m - l + 1;
		cnt[v * 2 + 1] = r - m;
	}
	//cout << "push " << v << " " << l << " " << r << " " << cnt[v * 2 + 1] << endl;
}

void _set(int l, int r, int num, int v, int tl, int tr) {
	if (tl > r || tr < l) return;
	if (tl >= l && tr <= r) {
		cnt[v] = num * (tr - tl + 1);
		//cout << tl << " " << tr << " " << cnt[v] << " " << v << endl;
		return;
	}
	push(v, tl, tr);
	int m = (tl + tr) / 2;
	_set(l, r, num, v * 2, tl, m);
	_set(l, r, num, v * 2 + 1, m + 1, tr);
	cnt[v] = cnt[v * 2] + cnt[v * 2 + 1];
	//cout << tl << " " << tr << " " << v << " " << cnt[v * 2] << " " << cnt[v * 2 + 1] << endl;
}

int _get(int l, int r, int v, int tl, int tr) {
	//cout << v << " " << tl << " " << tr << endl;
	if (tl > r || tr < l) return 0;
	if (tl >= l && tr <= r) return cnt[v];
	push(v, tl, tr);
	int m = (tl + tr) / 2;
	return _get(l, r, v * 2, tl, m) + _get(l, r, v * 2 + 1, m + 1, tr);
}

void solve() {
	int q;
	cin >> n >> q;
	for(int i = 0;i <= 2 * n;i++)
		cnt[i] = 0;

	string s, f;
	cin >> s >> f;
	for(int i = 0;i < n;i++) {
		_set(i, i, f[i] - '0', 1, 0, n - 1);
	}	
	vector<pii> a(q);
	for(int i = 0;i < q;i++) {
		cin >> a[i].fi >> a[i].se;
	}
	reverse(all(a));
	bool bad = false;
	for(pii i : a) {
		//cout << i.fi << " " << i.se << endl;
		i.fi--; i.se--;
		int num = _get(i.fi, i.se, 1, 0, n - 1);
		//cout << num << endl;

		if (2 * num == i.se - i.fi + 1) bad = true;
		_set(i.fi, i.se, 2 * num > (i.se - i.fi + 1), 1, 0, n - 1);
	}
	for(int i = 0;i < n;i++) {
		if (s[i] - '0' != _get(i, i, 1, 0, n - 1)) bad = true;
	}
	cout << (bad ? "NO" : "YES") << endl;
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