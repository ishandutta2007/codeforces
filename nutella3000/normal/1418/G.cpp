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
const int max_n = (1 << 19);

int n;
int a[max_n];
vector<int> b[max_n];

int mn[2 * max_n], cnt[2 * max_n], push[2 * max_n];

void build_seg() {
	for(int i = 2 * max_n - 1;i >= 1;i--) {
		if (i >= max_n) cnt[i] = 1;
		else cnt[i] = 2 * cnt[i * 2];
	}
}

void upd(int v, int x) {
	mn[v] += x;
	push[v] += x;
}

void pushing(int v) {
	upd(v * 2, push[v]);
	upd(v * 2 + 1, push[v]);
	push[v] = 0;
}

void seg_set(int l, int r, int x, int v = 1, int tl = 0, int tr = max_n - 1) {
	if (tl > r || tr < l) return;
	if (tl >= l && tr <= r) {
		upd(v, x);
		return;
	}
	pushing(v);
	int mid = (tl + tr) / 2;
	seg_set(l, r, x, v * 2, tl, mid);
	seg_set(l, r, x, v * 2 + 1, mid + 1, tr);
	mn[v] = min(mn[v * 2], mn[v * 2 + 1]);
	cnt[v] = cnt[v * 2] * (mn[v * 2] == mn[v]) + cnt[v * 2 + 1] * (mn[v * 2 + 1] == mn[v]);
}

int seg_get(int l, int r, int v = 1, int tl = 0, int tr = max_n - 1) {
	if (tl > r || tr < l) return 0;
	if (tl >= l && tr <= r) return (mn[v] == 0 ? cnt[v] : 0);
	pushing(v);
	int mid = (tl + tr) / 2;
	return seg_get(l, r, v * 2, tl, mid) + seg_get(l, r, v * 2 + 1, mid + 1, tr);
}

void solve() {
	build_seg();

	cin >> n;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		b[a[i]].emplace_back(i);
	}
	for(int i = 1;i <= n;i++)
		b[i].emplace_back(n), b[i].emplace_back(n), b[i].emplace_back(n);
	
	int r = n - 1;
	int res = 0;
	for(int l = n - 1;l >= 0;l--) {
		int c = a[l];
		int id = lower_bound(all(b[c]), l) - b[c].begin();
		seg_set(b[c][id], b[c][id + 2] - 1, 1);
		seg_set(b[c][id + 1], b[c][id + 3] - 1, -1);
		chkmin(r, b[c][id + 3] - 1);
		res += seg_get(l, r);
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