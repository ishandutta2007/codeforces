#include <stdio.h>
#include <bits/stdc++.h>
#define mid ((l + r) >> 1)

using namespace std;

const int N = 5e4 + 10; 
typedef long long ll;

ll k; int P , n , m , s[N];

struct Matrix {
	int a[2][2];
	Matrix() {memset(a , 0 , sizeof a);}
	void make() {a[0][0] = a[1][1] = 1;}
	void output() {
		for(int i = 0; i < 2; i++ , cout << endl)
			for(int j = 0; j < 2; j++)
				cout << a[i][j] << " ";
	}
	inline friend Matrix operator * (Matrix A , Matrix B) {
		Matrix ret;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++) {
				ll tmp = 0;
				for(int k = 0; k < 2; k++)
					tmp += 1ll * A.a[i][k] * B.a[k][j];
				ret.a[i][j] = tmp % P;
			}
		return ret;
	}
};

inline Matrix Pow(Matrix x , ll y) {
	Matrix ret; ret.make();
	while(y) {
		if(y & 1) ret = ret * x;
		x = x * x , y >>= 1;
	}
	return ret;
}

Matrix o[N << 2];

inline void update(int p) {
	o[p] = o[p << 1] * o[p << 1 | 1];
}

void build(int p , int l , int r) {
	if(l == r) {
		o[p].a[1][0] = 1 , o[p].a[0][1] = s[l - 1] , o[p].a[1][1] = s[l % n];
		return;
	}
	build(p << 1 , l , mid) , build(p << 1 | 1 , mid + 1 , r);
	update(p);
}

void add(int p , int l , int r , int s , int t , int v) {
	if(l == r) {
		if(t == 1) o[p].a[0][1] = v;
		else o[p].a[1][1] = v;
		return;
	}
	if(s <= mid) add(p << 1 , l , mid , s , t , v);
	else add(p << 1 | 1 , mid + 1 , r , s , t , v);
	update(p);
}

Matrix query(int p , int l , int r , int tl , int tr) {
	if(tl <= l && r <= tr) return o[p];
	Matrix ret; ret.make();
	if(tl <= mid) ret = ret * query(p << 1 , l , mid , tl , tr);
	if(tr > mid) ret = ret * query(p << 1 | 1 , mid + 1 , r , tl , tr);
	return ret; 
}

struct Query {
	ll p , t , v;
	Query(ll p = 0 , ll t = 0 , ll v = 0) : p(p) , t(t) , v(v) {} 
}	q[N << 1];

inline bool operator < (Query A , Query B) {
	return A.p < B.p;
}

inline ll wh(ll x) {return (x - 1) / n + 1;}

int main() {
	ios::sync_with_stdio(false);
	cin >> k >> P >> n;
	if(k == 0) return cout << 0 << endl , 0;
	if(k == 1) return cout << 1 % P << endl , 0;
	k--;
	for(int i = 0; i < n; i++) cin >> s[i];
	build(1 , 1 , n) , cin >> m;
	for(int i = 1; i <= m; i++) {
		ll a , b; cin >> a >> b;
		q[i * 2 - 1] = Query(a , 2 , b);
		q[i * 2] = Query(a + 1 , 1 , b);
	}
	sort(q + 1 , q + 2 * m + 1) , m *= 2;
	for(int i = m; i >= 1; i--)
		if(q[i].p > k) m--;
	ll t = 1 , now = 1; Matrix A; A.make();
	while(t <= m) {
		if(wh(q[t].p) == wh(k))	break;
		ll tmp = wh(q[t].p) , from = t; A = A * Pow(o[1] , tmp - now) , now = tmp + 1;
		while(t <= m && tmp == wh(q[t].p)) t++;
		for(int i = from; i < t; i++) add(1 , 1 , n , q[i].p % n ? q[i].p % n : n , q[i].t , q[i].v);
		A = A * o[1];
		for(int i = from; i < t; i++) {
			if(q[i].t == 1)
				add(1 , 1 , n , q[i].p % n ? q[i].p % n : n , q[i].t , s[(q[i].p - 1) % n]);
			else
				add(1 , 1 , n , q[i].p % n ? q[i].p % n : n , q[i].t , s[q[i].p % n]);
		}
	}
	A = A * Pow(o[1] , wh(k) - now);
	for(int i = t; i <= m; i++) add(1 , 1 , n , q[i].p % n ? q[i].p % n : n , q[i].t , q[i].v);
	A = A * query(1 , 1 , n , 1 , k % n ? k % n : n);
	cout << A.a[1][1] << endl;
	return 0;
}