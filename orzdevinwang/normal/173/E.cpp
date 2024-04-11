#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define sz(a) ((int) (a).size())
#define mkp make_pair
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7, All = 1e9 + 7, M = N * 20;

struct SegmentTree /* changruinian2020! */ {
	int rt, mx[M], ch[M][2], tot;
	void upd(int id) { mx[id] = max(mx[ch[id][0]], mx[ch[id][1]]); }
	void add(int &id, int L, int R, int x, int w) {
		if(x < L || R < x) return ;
		if(!id) id = ++tot, mx[id] = -1;
		if(L == R) return mx[id] = max(mx[id], w), void();
		int mid = (L + R) >> 1;
		add(ch[id][0], L, mid, x, w), add(ch[id][1], mid + 1, R, x, w), upd(id);
	}
	int qry(int id, int L, int R, int l, int r) {
		if(r < L || R < l || !id) return -1;
		if(l <= L && R <= r) return mx[id]; 
		int mid = (L + R) >> 1;
		return max(qry(ch[id][0], L, mid, l, r), qry(ch[id][1], mid + 1, R, l, r));
	}
} s2;
struct fenwick {
	int f[N];
	void add(int x, int w) {
		for(; x < N; x += (x & -x)) f[x] += w;
	}
	int qzh(int x) {
		int res = 0;
		for(; x; x -= (x & -x)) res += f[x];
		return res;
	}
	int sum(int l, int r) {
		return qzh(r) - qzh(l - 1);
	}
} s1;

int n, k, q, ns[N];

struct qry {
	int r, l, pr, id;
} s[N];

struct node {
	int r, a, val;
} a[N];
vi v[N];
int arr[N], atot;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	s2.mx[0] = -1, cin >> n >> k;
	L(i, 1, n) cin >> a[i].r, arr[++atot] = a[i].r;
	sort(arr + 1, arr + atot + 1), atot = unique(arr + 1, arr + atot + 1) - arr - 1;
	L(i, 1, n) a[i].r = lower_bound(arr + 1, arr + atot + 1, a[i].r) - arr;
	L(i, 1, n) cin >> a[i].a;
	cin >> q;
	L(t, 1, q) {
		int x, y;
		cin >> x >> y;
		s[t].l = max(max(a[x].a, a[y].a) - k, 0);
		s[t].r = min(min(a[x].a, a[y].a) + k, All);
		s[t].pr = max(a[x].r, a[y].r);
		s[t].id = t;
	}
	sort(s + 1, s + q + 1, [&] (qry a, qry b) { return a.pr > b.pr; });
	sort(a + 1, a + n + 1, [&] (node a, node b) { return a.a < b.a; } );
	int sl = 1, sr = 0;
	L(i, 1, n) {
		while(sr < n && a[sr + 1].a - a[i].a <= k) ++sr, s1.add(a[sr].r, 1);
		while(sl <= n && a[i].a - a[sl].a > k) s1.add(a[sl].r, -1), ++sl;
		a[i].val = s1.qzh(a[i].r);
	}
	// L(i, 1, n) cout << a[i].a << " " << a[i].r << " : " << a[i].val << "\n";
	// cout << "\n";
	sort(a + 1, a + n + 1, [&] (node a, node b) { return a.r > b.r; } );
	int p = 1;
	L(i, 1, q) {
		while(p <= n && a[p].r >= s[i].pr) s2.add(s2.rt, 0, All, a[p].a, a[p].val), ++p;
		ns[s[i].id] = s2.qry(s2.rt, 0, All, s[i].l, s[i].r);
	}
	L(i, 1, q) cout << ns[i] << "\n";
	return 0;
}