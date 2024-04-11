#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 22;
int n, dd, tp;
struct node {
	int s, a;
} p[N];
int tag[N], mx[N];
void upd (int x) {
	mx[x] = max(mx[x << 1 | 1], mx[x << 1]);
}
void ADD (int x, int w) {
	tag[x] += w, mx[x] += w;
}
void push (int x) {
	if(tag[x]) ADD (x << 1, tag[x]), ADD (x << 1 | 1, tag[x]), tag[x] = 0;
}
void add (int x, int L, int R, int l, int r, int w) {
	if(l <= L && R <= r) return ADD(x, w), void ();
	int mid = (L + R) >> 1;
	push (x);
	if(l <= mid) add (x << 1, L, mid, l, r, w);
	if(r > mid) add (x << 1 | 1, mid + 1, R, l, r, w);
	upd (x);
}
int query (int x, int L, int R, int l, int r) {
	if(l <= L && R <= r) return mx[x];
	push (x);
	int mid = (L + R) >> 1, ret = 0;
	if(l <= mid) ret = max(ret, query (x << 1, L, mid, l, r));
	if(r > mid) ret = max(ret, query (x << 1 | 1, mid + 1, R, l, r));
	return ret;
}

template < int N > struct fenwt {
	using F = long long ;
	F a[N + 1];
	void add (int x, F w) {
		for (; x <= N; x += x & -x) a[x] += w;
	}
	F query (int x) {
		F ret = 0;
		for (; x; x -= x & -x) ret += a[x];
		return ret;
	}
	F get (int l, int r) {
		if(l > r) return 0;
		return query (r) - query (l - 1);
	}
} ;
fenwt < N > cc;

int dp[N];
int arr[N], atot;
vi ww[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> dd;
	atot = 0;
	arr[++atot] = dd;
	L(i, 1, n) {
		cin >> p[i].s >> p[i].a;
		if(p[i].s < dd) {
			continue;
		}
		p[++tp] = p[i];
	}
	n = tp;
	L(i, 1, n) arr[++atot] = p[i].s, arr[++atot] = p[i].a;
	sort(arr + 1, arr + atot + 1);
	atot = unique(arr + 1, arr + atot + 1) - arr - 1;
	L(i, 1, n) p[i].s = lower_bound(arr + 1, arr + atot + 1, p[i].s) - arr;
	L(i, 1, n) p[i].a = lower_bound(arr + 1, arr + atot + 1, p[i].a) - arr;
	dd = lower_bound(arr + 1, arr + atot + 1, dd) - arr;
	sort (p + 1, p + n + 1, [&] (node a, node b) {
		return a.a == b.a ? a.s < b.s : a.a < b.a;
	});
	int ns = 0;
	int pos = 1;
	while (pos <= n && p[pos].a <= dd) pos += 1;
	L(i, pos, n) add (1, 0, n, 0, i - 1, 1), cc.add (i, 1);
	L(i, pos, n) ww[p[i].s].push_back(i);
	L(i, 1, pos - 1) 
		add (1, 0, n, i, i, -1e9);
	int lst = 0;
	L(i, pos, n) {
		L(t, lst, p[i].a - 1) 
			for (const int &g : ww[t]) {
				add (1, 0, n, 0, g - 1, -1), cc.add (g, -1); 
			}
		lst = p[i].a;
		int l = 1, r = i - 1, fns = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if(p[i].s >= p[mid].a) fns = mid, l = mid + 1;
			else r = mid - 1;
		}
		dp[i] = query (1, 0, n, 0, fns) - cc.get(i, n);
		dp[i] = max(dp[i], 0);
		dp[i] += 1;
		ns = max (ns, dp[i]);
		add (1, 0, n, i, i, dp[i]);
	}
	cout << ns + pos - 1 << '\n';
	return 0;
}
/*
2 5
7 4
7 6
*/