#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 1 << 20;
struct node {
	int siz;
	ll w, ns;
	inline node (int sz = 0, ll W = 0) { 	
		siz = sz, w = W, ns = 0;
	}
} ;
bool operator <= (node a, node b) {
	return (ll) a.w * b.siz <= (ll) b.w * a.siz;
}
struct Data {
	int cnt;
	vector < node > f;
	ll ns;
} E, v0, v1; // ;  0  1
Data operator * (Data a, Data b) { 
	a.ns += b.ns;
	if(sz(b.f)) {
		b.f[0].w += a.cnt, a.cnt = b.cnt;
		for(auto u : b.f) a.f.emplace_back(u);
	} else {
		a.cnt += b.cnt; 
	}
	vector < node > s;
	for(auto u : a.f) {
		s.emplace_back(u);
		while(sz(s) >= 3) {
			int xn = sz(s) - 1;
			if(s[xn - 1] <= s[xn]) {
				a.ns += (ll) s[xn - 1].siz * s[xn].w;
				s[xn - 1].siz += s[xn].siz;
				s[xn - 1].w += s[xn].w;
				s.pop_back();
			} else break;
		}
	}
	a.f = s;
	return a;
}
Data operator ^ (Data a, int b) {
	Data ret = E;
	for (; b; b >>= 1, a = a * a) if(b & 1) ret = ret * a;
	return ret;
}
Data solve (int a, int b, int c, int n, Data x, Data y) {
	b %= c;
	if(a >= c) return solve(a % c, b, c, n, x, (x ^ (a / c)) * y);
	else {
		int m = ((ll) a * n + b) / c;
		if(m == 0) return y ^ n;
		return (y ^ ((c - b - 1) / a)) * x * 
			solve(c, c - b - 1, a, m - 1, y, x) * (y ^ (n - ((ll) m * c - b - 1) / a));
	}
}

namespace qwq {
int n;
int fa[N], f[N], siz[N];
ll w[N]; 
struct node {
	int x, fm;
	ll fz;
	inline node (int X = 0, ll FZ = 0, int FM = 0) { x = X, fz = FZ, fm = FM; }
} ;
inline bool operator < (node a, node b) { 
	return a.fz * b.fm < b.fz * a.fm; 
}
priority_queue < node > q;
inline int find (int x) {
	return f[x] == x ? x : f[x] = find (f[x]);
}
ll solve() {
	ll ns = 0;
	L(i, 1, n) f[i] = i, q.push(node (i, w[i], siz[i]));
	siz[0] = 0;
	while (!q.empty()) {
		int z = q.top().x;
		q.pop();
		if(find(z) != z) continue;
		int Fa = find(fa[z]);
		ns += (ll) siz[Fa] * w[z];
		w[Fa] += w[z], siz[Fa] += siz[z], f[z] = Fa;
		if(Fa) q.push(node(Fa, w[Fa], siz[Fa]));
	}
	return ns;
}
	
}

int n, d, hp, a[N];
ll s, ns;
int tot;
void Main() {
	cin >> n >> d >> hp;
	L(i, 1, n) cin >> a[i];
	ns = 0;
	
	L(i, 1, n) a[i] *= hp;
	tot = 0;
	L(i, 1, n) {
		int lst = 0, cnt = (a[i] + d - 1) / d;
//		L(t, 1, cnt - 1) {
//			++tot, qwq :: fa[tot] = lst, lst = tot;
//			qwq :: w[tot] = t * d / hp - (t - 1) * d / hp;
//		} 
		auto u = solve(d, 0, hp, cnt - 1, v0, v1);
		ns += u.ns;
		for(auto p : u.f) {
			++tot, qwq :: fa[tot] = lst, lst = tot;
			qwq :: siz[tot] = p.siz, qwq :: w[tot] = p.w;
//			cout << p.siz << "," << p.w << endl;
		}
//		cout << endl;
		++tot, qwq :: fa[tot] = lst, qwq :: siz[tot] = 1;
		qwq :: w[tot] = a[i] / hp - (cnt - 1) * d / hp;
	}
	qwq :: n = tot;
	cout << ns + qwq :: solve() + 1 << '\n';
}
int main() {
	E.cnt = 0, E.f = {}, E.ns = 0;
	v0.cnt = 1, v0.f = {}, v0.ns = 0;
	v1.cnt = 0, v1.f = {node(1, 0)}, v1.ns = 0;
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}