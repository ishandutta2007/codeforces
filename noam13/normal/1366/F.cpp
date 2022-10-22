#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const long long INF = 1e18;
const int MOD = 1000'000'007;
const int inv2 = (MOD + 1) / 2;

struct edge{
	int v, u, w;
};

struct frac{
	long long x, y;
	frac(long long a, long long b){
		if (b < 0) a = -a, b = -b;
		x = a, y = b;
	}
};

bool operator <=(const frac &a, const frac &b){
	return a.x * b.y <= a.y * b.x;
}

struct line{
	long long m, c;
	frac intersectX(const line &l) { return frac(c - l.c, l.m - m); }
};

int add(int a, int b){
	a += b;
	if (a >= MOD)
		a -= MOD;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b){
	return a * 1ll * b % MOD;
}

int calc(int a1, int d, int n){
	assert(n >= 0);
	return mul(mul(n, inv2), add(mul(2, a1), mul(add(n, -1), d)));
}

int main() {
	int n, m;
	long long q;
	scanf("%d%d%lld", &n, &m, &q);
	vector<edge> e(m);
	vector<int> hv(n);
	forn(i, m){
		scanf("%d%d%d", &e[i].v, &e[i].u, &e[i].w);
		--e[i].v, --e[i].u;
		hv[e[i].v] = max(hv[e[i].v], e[i].w);
		hv[e[i].u] = max(hv[e[i].u], e[i].w);
	}
	
	int ans = 0;
	vector<long long> d(n, -INF), nd(n);
	d[0] = 0;
	forn(val, m){
		long long mx = 0;
		forn(i, n)
			mx = max(mx, d[i]);
		if (val)
			ans = add(ans, mx % MOD);
		nd = d;
		forn(i, m){
			nd[e[i].v] = max(nd[e[i].v], d[e[i].u] + e[i].w);
			nd[e[i].u] = max(nd[e[i].u], d[e[i].v] + e[i].w);
		}
		d = nd;
	}
	
	vector<line> fin;
	forn(i, n) fin.push_back({hv[i], d[i]});
	sort(fin.begin(), fin.end(), [](const line &a, const line &b){
		if (a.m != b.m)
			return a.m < b.m;
		return a.c > b.c;
	});
	fin.resize(unique(fin.begin(), fin.end(), [](const line &a, const line &b){
		return a.m == b.m;
	}) - fin.begin());
	
	vector<line> ch;
	for (auto cur : fin){
		while (ch.size() >= 2 && cur.intersectX(ch.back()) <= ch.back().intersectX(ch[int(ch.size()) - 2]))
			ch.pop_back();
		ch.push_back(cur);
	}
	
	long long prv = 0;
	q -= m;
	forn(i, int(ch.size()) - 1){
		frac f = ch[i].intersectX(ch[i + 1]);
		if (f.x < 0) continue;
		long long lst = min(q, f.x / f.y);
		if (lst < prv) continue;
		ans = add(ans, calc((ch[i].c + ch[i].m * prv) % MOD, ch[i].m % MOD, lst - prv + 1));
		prv = lst + 1;
	}
	ans = add(ans, calc((ch.back().c + ch.back().m * prv) % MOD, ch.back().m % MOD, q - prv + 1));
	
	printf("%d\n", ans);
	return 0;
}