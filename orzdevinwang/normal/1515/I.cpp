#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7, M = 1 << 19;
const ll linf = 1e18;
int n, m, mp[N];
struct pr {
	int w, v, id;
	ll a;
};
pr s[N];
struct TouXiGod {
	ll sumv[M], sumw[M], tag[M], mx[M], mn2[M];
	void modify(int x, int p, int w, int L, int R) {
		sumv[x] += (ll) s[p].v * w, sumw[x] += (ll) s[p].w * w;
		if(L == R) return;
		int mid = (L + R) >> 1;
		if(p <= mid) modify(x * 2, p, w, L, mid);
		else modify(x * 2 + 1, p, w, mid + 1, R);
	}
	void sadd(int x, int p, ll v, int L, int R) {
		if(L == R) return mn2[x] = v + tag[x], void();
		int mid = (L + R) >> 1;
		if(p <= mid) sadd(x * 2, p, v, L, mid);
		else sadd(x * 2 + 1, p, v, mid + 1, R);
		mn2[x] = min(mn2[x * 2], mn2[x * 2 + 1]) + tag[x];
	}
	void add(int x, int l, int r, ll v, int L, int R) {
		if(L > r || l > R) return;
		if(l <= L && R <= r) return tag[x] += v, mx[x] += v, mn2[x] += v, void();
		int mid = (L + R) >> 1;
		add(x * 2, l, r, v, L, mid), add(x * 2 + 1, l, r, v, mid + 1, R);
		mx[x] = max(mx[x * 2], mx[x * 2 + 1]) + tag[x], mn2[x] = min(mn2[x * 2], mn2[x * 2 + 1]) + tag[x];
	}
	ll Sumv(int x, int l, int r, int L, int R) {
		if(L > r || l > R) return 0;
		if(l <= L && R <= r) return sumv[x];
		int mid = (L + R) >> 1;
		return Sumv(x * 2, l, r, L, mid) + Sumv(x * 2 + 1, l, r, mid + 1, R);
	}
	ll Sumw(int x, int l, int r, int L, int R) {
		if(L > r || l > R) return 0;
		if(l <= L && R <= r) return sumw[x];
		int mid = (L + R) >> 1;
		return Sumw(x * 2, l, r, L, mid) + Sumw(x * 2 + 1, l, r, mid + 1, R);
	}
	int Get1(int x, int l, int r, ll val, int L, int R) { 
		if(mx[x] <= val || L > r || l > R) return -1;
		if(L == R) return L;
		val -= tag[x];
		int mid = (L + R) >> 1, v;
		return (v = Get1(x * 2, l, r, val, L, mid)) != -1 ? v : Get1(x * 2 + 1, l, r, val, mid + 1, R);
	}
	int Get2(int x, int l, int r, ll val, int L, int R) { 
		if(mn2[x] > val || L > r || l > R) return -1;
		if(L == R) return L;
		val -= tag[x];
		int mid = (L + R) >> 1, v;
		return (v = Get2(x * 2, l, r, val, L, mid)) != -1 ? v : Get2(x * 2 + 1, l, r, val, mid + 1, R);
	}
	ll Now = 0;
	void build(int x, int k, int L, int R) {
		if(L == R) {
			if((1 << k) <= s[L].v && s[L].v < (1 << (k + 1)) && s[L].a) mn2[x] = s[L].v;
			else mn2[x] = linf;
			if(s[L].v < (1 << k)) 
				sumv[x] = (ll) s[L].v * s[L].a, sumw[x] = (ll) s[L].w * s[L].a, Now += sumv[x];
			tag[x] += Now, mx[x] += Now, mn2[x] += Now;
			return;
		}
		int mid = (L + R) >> 1;
		build(x * 2, k, L, mid), build(x * 2 + 1, k, mid + 1, R);
		mx[x] = max(mx[x * 2], mx[x * 2 + 1]), mn2[x] = min(mn2[x * 2], mn2[x * 2 + 1]);
		sumv[x] = sumv[x * 2] + sumv[x * 2 + 1], sumw[x] = sumw[x * 2] + sumw[x * 2 + 1];
	}
} q[18];
int o, t[N];
bool isfirst[N];
void mdf(int x, int w) {
	L(i, 0, 17) if(s[x].v < (1 << i)) q[i].modify(1, x, w, 1, n), q[i].add(1, x, n, (ll) w * s[x].v, 1, n);
	int lg = log2(s[x].v);      
	if(!s[x].a) q[lg].sadd(1, x, s[x].v, 1, n);
	s[x].a += w;
	if(!s[x].a) q[lg].sadd(1, x, linf, 1, n);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> s[i].a >> s[i].v >> s[i].w, s[i].id = i;
	sort(s + 1, s + n + 1, [&] (pr a, pr b) {
		return a.w ^ b.w ? a.w > b.w : a.v < b.v;
	});
	L(i, 1, n) mp[s[i].id] = i;
	L(i, 0, 17) q[i].build(1, i, 1, n); 
	while(m--) {
		int op, x, y;
		cin >> op;
		if(op == 1) cin >> x >> y, mdf(mp[y], x);
		if(op == 2) cin >> x >> y, mdf(mp[y], -x);
		if(op == 3) {
			ll c, ns = 0;
			int o = 1;
			cin >> c;
			while(c && o <= n) {
				int B = log2(c);
				B = min(B, 17);
				ll qsum = q[B].Sumv(1, 1, o - 1, 1, n);
				int z = q[B].Get2(1, o, n, c + qsum, 1, n);
				if(z != -1) 
					c -= q[B].Sumv(1, o, z - 1, 1, n) + s[z].v, ns += q[B].Sumw(1, o, z - 1, 1, n) + s[z].w, o = z + 1;
				else {
					z = q[B].Get1(1, o, n, c - (1 << B) + qsum, 1, n);
					if(z == -1) z = n;
					c -= q[B].Sumv(1, o, z - 1, 1, n), ns += q[B].Sumw(1, o, z - 1, 1, n), o = z;
					int t = min(c / s[o].v, (ll) s[o].a);
					ns += (ll) t * s[o].w, c -= (ll) t * s[o].v;
					++o;
				}
			}
			cout << ns << '\n';
		}
	}
	return 0;
}