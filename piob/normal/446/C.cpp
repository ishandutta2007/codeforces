#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef pair<unsigned, unsigned> PUU;
typedef long long LL;
typedef long double K;

const int mod = 1000000009;
const LL INF = 2000000000LL * 2000000000LL;

struct matrix{ int T[3][3]; };

matrix operator*(matrix a, matrix b){
	matrix c;
	FWD(i,0,3) FWD(j,0,3) c.T[i][j] = 0;
	FWD(i,0,3) FWD(k,0,3) FWD(j,0,3)
		c.T[i][k] = (c.T[i][k] + (LL)a.T[i][j] * b.T[j][k]) % mod;
	return c;
}

matrix POW[300010];

typedef int val_t;

struct mod_t {
	int s, a, b;
};

mod_t advance(mod_t m, int k){
	if(k == 0) return m;
	matrix r = POW[k];
	return mod_t({
		m.s + k,
		(int)(((LL)m.a * r.T[0][0] + (LL)m.b * r.T[1][0]) % mod),
		(int)(((LL)m.a * r.T[0][1] + (LL)m.b * r.T[1][1]) % mod)
	});
}

int get_sum(mod_t m, int a, int b){
	m = advance(m, a-m.s);
	matrix r = POW[b-a];
	return ((LL)m.a * r.T[0][2] + (LL)m.b * r.T[1][2]) % mod;
}

val_t apply(val_t v, mod_t m, int x, int y){
	return (v + get_sum(m, x, y)) % mod;
}

mod_t bind(mod_t a, mod_t b){
	if(b.s < a.s) swap(a, b);
	a = advance(a, b.s-a.s);
	return mod_t({b.s, (a.a+b.a) % mod, (a.b+b.b) % mod});
}

val_t sum(val_t a, val_t b){
	return (a+b) % mod;
}

const val_t VAL_INIT = 0;
const mod_t MOD_ZERO = mod_t({0, 0, 0});		// neutral modifier
const int MAXD = 1024*1024;

struct segment_tree {
	int d; val_t V[MAXD]; mod_t M[MAXD];
	void init(int n, val_t* initial = NULL){
		d = 1; while(d < n) d *= 2;
		if(initial) FWD(i,0,n) V[d+i] = initial[i]; else n = 0;
		FWD(i,n,d) V[d+i] = VAL_INIT;
		BCK(i,d-1,0) V[i] = sum(V[2*i], V[2*i+1]);
		FWD(i,1,2*d) M[i] = MOD_ZERO; 
	}
	void modify(int x, int y, mod_t m){ _modify(1,0,d,x,y,m); }	// applies m on [x, y)
	val_t query(int x, int y){ return _query(1,0,d,x,y); }		// gets val_t of [x, y)
	void _bind(int u, mod_t m){ M[u] = bind(M[u], m); }
	void _push(int u, int a, int b){
		if(M[u].a == 0 && M[u].b == 0) return;
		V[u] = apply(V[u], M[u], a, b);
		if(u<d) _bind(2*u, M[u]), _bind(2*u+1, M[u]);
		M[u] = MOD_ZERO;
	}
	void _modify(int u, int a, int b, int x, int y, mod_t m){
		_push(u, a, b);
		if(x <= a && b <= y){
			_bind(u, m); _push(u, a, b);
			return;
		}
		if(x<(a+b)/2) _modify(2*u, a, (a+b)/2, x, y, m); else _push(2*u, a, (a+b)/2);
		if((a+b)/2<y) _modify(2*u+1, (a+b)/2, b, x, y, m); else _push(2*u+1, (a+b)/2, b);
		V[u] = sum(V[2*u], V[2*u+1]);
	}
	val_t _query(int u, int a, int b, int x, int y){
		_push(u, a, b);
		if(x <= a && b <= y) return V[u];
		if(y <= (a+b)/2) return _query(2*u, a, (a+b)/2, x, y);
		if((a+b)/2 <= x) return _query(2*u+1, (a+b)/2, b, x, y);
		return sum(_query(2*u, a, (a+b)/2, x, y), _query(2*u+1, (a+b)/2, b, x, y));
	}
} S;

int n, m;
int A[300010];

int main(){
	matrix a;
	FWD(i,0,3) FWD(j,0,3) POW[0].T[i][j] = (i==j?1:0), a.T[i][j] = 0;
	a.T[0][1] = a.T[0][2] = a.T[1][0] = a.T[1][1] = a.T[2][2] = 1;
	FWD(i,1,300010) POW[i] = POW[i-1] * a;
	scanf("%d %d", &n, &m);
	FWD(i,0,n) scanf("%d", &A[i]);
	S.init(n, A);
	FWD(i,0,m){
		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);
		--a;
		if(t == 1){
			S.modify(a, b, {a, 1, 1});
		}else{
			printf("%d\n", S.query(a, b));
		}
	}
	return 0;
}