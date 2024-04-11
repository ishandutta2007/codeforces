#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1 << 20, inf = 1e9 + 7;
int n, m;
int f[N], ql[N], qr[N], qk[N];
ll ns = -1e18, wl[N], wr[N];
ll dp[N];
vi Sl[N], Sr[N];



//int curdep;
//int vl[20][N];
//int vr[20][N];
//void solve(int l, int r, vi qwq, ll cov) {
//	if(l > r) return ;
//	int mid = (l + r) >> 1;
//	
//	L(i, l - 1, r) dp[i] = -1e18;
//	L(i, l - 1, mid - 1) dp[i] = wl[i + 1];
//	
//	L(i, l - 1, mid - 1) {
//		for(const int &u : Sr[i]) {
//			ll ret = -1e18;
//			int tx = max(ql[u] - 1, l - 1);
//			L(j, tx, i - 1) 
//				ret = max(ret, dp[j]);
//			dp[i] = max(dp[i], ret - qk[u]);
//		}
//	}
//	R(i, r, mid) {
//		dp[i] = wr[i];
//		for(const int &u : Sl[i]) {
//			ll ret = -1e18;
//			int ty = max(qr[u] - 1, r);
//			L(j, i + 1, ty) 
//				ret = max(ret, dp[j]);
//			dp[i] = max(dp[i], ret - qk[u]);
//		}
//	}
//	
//	
////	if(l == 1 && r == n) cout << sz(S[3]) << ' ' << "DP = " << dp[3] << '\n';
//	ll mx = -1e18;
//	R(i, r, mid) {
//		mx = max(mx, dp[i]), ns = max(ns, mx + wr[i]);
//		if(mx + wr[i] + 16 == 16) 
//			cout << "qwq : " << l << ' ' << r << ' ' << mid << ' ' << i << '\n';
//	}
//	
//	L(i, l, r) vl[curdep + 1][i] = vl[curdep][i], vr[curdep + 1][i] = vr[curdep][i];
//	L(i, mid, r) vl[curdep + 1][mid - 1] = min(vl[curdep + 1][mid - 1], vl[curdep][i]);
//	L(i, l, mid) vl[curdep + 1][mid - 1] = min(vl[curdep + 1][mid - 1], vl[curdep][i]);
//	
//	vi qwql, qwqr;
//	for(const int &u : qwq) {
//		if(qr[u] < mid) qwql.emplace_back(u);
//		else if(ql[u] > mid) qwqr.emplace_back(u);
//		else vl[ql[u]] = min(vl[ql[u]], qw[u]), vr[qr[u]] = min(vr[qr[u]], qw[u]);
//	}
//	
//	++curdep;
//	solve(l, mid - 1);
//	solve(mid + 1, r);
//	--curdep;
//}

multiset < int > mut[N];
struct node {
	ll x, y, ns;
	node (ll X = -1e18, ll Y = -1e18, ll NS = -1e18) {
		x = X, y = Y, ns = NS;
	}
}; 
node operator + (node a, node b) {
	return node(max(a.x, b.x), max(a.y, b.y), max(max(a.ns, b.ns), a.y + b.x));
}
node F[N];
void add(int x, int L, int R, int p, int w, int op) {
	if(L == R) {
		if(op == 1) {
			mut[x].insert(w);
		} else {
			mut[x].erase(mut[x].lower_bound(w));
		}
		if(sz(mut[x])) F[x].y = *mut[x].rbegin();
		else F[x].y = -1e18;
		return ;
	}
	int mid = (L + R) >> 1;
	p <= mid ? add(x << 1, L, mid, p, w, op) : add(x << 1 | 1, mid + 1, R, p, w, op);
	F[x] = F[x << 1] + F[x << 1 | 1];
}
void ups(int x, int L, int R, int p, ll w) {
	if(L == R) return F[x].x = w, void();
	int mid = (L + R) >> 1;
	p <= mid ? ups(x << 1, L, mid, p, w) : ups(x << 1 | 1, mid + 1, R, p, w);
	F[x] = F[x << 1] + F[x << 1 | 1];
}

int main () { 
//	me(va, 0x3f);
//	me(vb, 0x3f);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> wl[i];
	L(i, 1, n) cin >> f[i];
	L(i, 1, n) cin >> wr[i];
	
	L(i, 1, n) {
		
	}
	
	L(i, 1, n) wl[i] += wl[i - 1];
	R(i, n, 1) wr[i] += wr[i + 1];
	
	ll cur = 0;
	L(i, 1, n) wl[i] -= cur, cur += f[i];
	cur = 0;
	R(i, n, 1) wr[i] -= cur, cur += f[i];
	
//	cout << "cur = " << cur << '\n';
	
	L(i, 1, m) {
		cin >> ql[i] >> qr[i] >> qk[i];
		Sr[qr[i]].emplace_back(i);
		Sl[ql[i]].emplace_back(i);
		add(1, 0, n + 1, ql[i] - 1, -qk[i], 1);
	}
	
//	solve(1, n);
	L(i, 0, n) {
		dp[i] = F[1].ns;
		if(i) ns = max(ns, dp[i] + wr[i]);
		if(i != n) dp[i] = max(dp[i], wl[i + 1]); //cout << "DP : " << wl[i + 1] << '\n';
//		cout << i << " : " << dp[i] << '\n';
//		cout << "geting is " << F[1].x << ' ' << F[1].y << ' ' << F[1].ns << '\n';
		ups(1, 0, n + 1, i + 1, dp[i]);
		for(const int &u : Sr[i]) 
			add(1, 0, n + 1, ql[u] - 1, -qk[u], -1);
	}
	
	cout << cur + ns << '\n';
	return 0;
}