#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define upd(a, b) (a = min(a, b))

using namespace std;
const int N = 155;
typedef long long ll;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
int n, m;
struct edge {
	int a, b, d;
	bool operator <(const edge& o)const { return d < o.d; }
} e[N];
struct Matrix {
	ll a[N][N];
	ll* operator [](int key) { return a[key]; }
	Matrix() { mem(a, 63); }
	Matrix operator *(Matrix& b) {
		Matrix c;
		rep(i, 1, n) rep(k, 1, n) if(a[i][k] < Inf)
		rep(j, 1, n) upd(c[i][j], a[i][k] + b[k][j]);
		return c;
	}
} R, A, B;
struct node {
	int u; ll d;
	bool operator <(const node& o)const { return d > o.d; }
};
ll Dji() {
	static ll dis[N];
	priority_queue <node> q;
	rep(i, 1, n) if((dis[i] = R[1][i]) < Inf) q.push({ i, dis[i] });
	while(!q.empty()) {
		node x = q.top(); q.pop();
		if(x.u == n) return x.d;
		rep(i, 1, n) if(dis[x.u] + A[x.u][i] < dis[i])
			q.push({ i, dis[i] = dis[x.u] + A[x.u][i] });
	}
	return Inf;
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	rep(i, 1, m) scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].d);
	sort(e + 1, e + m + 1);
	R[1][1] = 0;
	rep(i, 1, m) {
		if(Dji() < e[i].d) cout << Dji(), exit(0);
		B = A;
		for(int k = e[i].d - e[i - 1].d; k; k /= 2, B = B * B)
		if(k & 1) R = R * B;
		A[e[i].a][e[i].b] = 1;
	}
	rep(i, 1, n) A[i][i] = 0;
	for(int k = n - 1; k; k /= 2, A = A * A)
	if(k & 1) R = R * A;
	if(R[1][n] < Inf) cout << R[1][n];
	else puts("Impossible");
}