#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f)) 
#define uint unsigned int
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
} 
int C(int x, int y) {
	return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

int n, a[N], b[N];
vi x0, x1;

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
	void clear() {
		memset(a, 0, sizeof(a));
	}
} ;

fenwt < N > A;

inline int gt0(int x) {
	return x + A.get(1, x - 1);
} 
inline int gt1(int x) {
	return x + A.get(x + 1, n * 3);
} 

int cnt[N];
pair < int, int > mx[N * 2];
int tag[N * 2];
void mark(int x, int w) {
	tag[x] += w, mx[x].first += w;
} 
void push(int x) {
	if(tag[x]) mark(x << 1, tag[x]), mark(x << 1 | 1, tag[x]), tag[x] = 0;
}	
void up(int x) {
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
}
void add(int x, int L, int R, int l, int r, int w) {
	if(l <= L && R <= r) 
		return mark(x, w);
	push(x);
	int mid = (L + R) >> 1;
	if(l <= mid) add(x << 1, L, mid, l, r, w);
	if(r > mid) add(x << 1 | 1, mid + 1, R, l, r, w);
	up(x);
}
void dec(int x, int L, int R, int p) {
	if(L == R) {
		cnt[p] -= 1;
		if(!cnt[p]) mx[x] = make_pair(-1e9, p);
		return ;
	}
	int mid = (L + R) >> 1;
	push(x); p <= mid ? dec(x << 1, L, mid, p) : dec(x << 1 | 1, mid + 1, R, p); up(x);
}
void build(int x, int L, int R) {
	tag[x] = 0;
	if(L == R) {
		if(cnt[L]) mx[x] = make_pair(gt1(L), L);
		return ;
	} 
	int mid = (L + R) >> 1;
	build(x << 1, L, mid), build(x << 1 | 1, mid + 1, R); up(x);
}
void init() {
	A.clear(), me(cnt, 0);
	for(const int &u : x0) A.add(u, 1);
	for(const int &u : x1) A.add(u, 1), cnt[u] += 1;
}

int curV, V0 = -1, V1 = -1;

void g0(int x) {
	A.add(x, -1), A.add(curV, 1);
	if(x < curV) add(1, 1, n * 2, x, curV - 1, 1); 
}
void g1(int x) {
	A.add(x, -1), A.add(curV, 1);
	if(x < curV) add(1, 1, n * 2, x, curV - 1, 1); 
	dec(1, 1, n * 2, x);
}

inline int slv(int x) {
	init(), build(1, 1, n * 2), curV = x;
	int p0 = 0, p1 = 0;
	while(p1 < sz(x1) && x1[p1] == x) g1(x), ++p1;
	L(c, 1, n - p1) {
		int a0 = (p0 < sz(x0) ? x0[p0] : -1);
		if(mx[1].first > x) return 0;
		int a1 = mx[1].first == x ? mx[1].second : -1;
		bool ok0 = a0 > 0 && gt0(a0) == x;
		bool ok1 = a1 > 0 && gt1(a1) == x;
		if(!ok0 && !ok1) return 0;
		if(ok0 && ok1) {
			if(a0 > a1) g0(a0), ++p0;
			else g1(a1);
		} else if(ok0) g0(a0), ++p0;
		else g1(a1);
	}
	return C(n, p1);
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init(N - 7);
	cin >> n;
	L(i, 1, n) {
		cin >> a[i];
	}
	L(i, 1, n) {
		cin >> b[i];
		if(b[i] == 0) {
			x0.push_back(a[i]);
		} else {
			x1.push_back(a[i]);
		}
	}
	sort(x0.begin(), x0.end());
	sort(x1.begin(), x1.end()), reverse(x1.begin(), x1.end());
	
	int lst = -1, prd = 1, cur = 0;
	for(const int &u : x0) {
		if(u != lst) cur = 0;
		cur += 1, prd = (ll) prd * cur % mod, lst = u;
	}
	lst = -1;
	for(const int &u : x1) {
		if(u != lst) cur = 0;
		cur += 1, prd = (ll) prd * cur % mod, lst = u;
	}
	
	init(), V0 = sz(x0) ? gt0(x0[0]) : -1;
	for(const int&u : x1) 
		V1 = max(V1, gt1(u));
	int ns = 0;
	L(i, 0, n * 3) if(i == V0 || i == V1) (ns += slv(i)) %= mod;
	cout << (ll) ns * prd % mod << '\n';
	return 0;
}