#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
const int inf = 1e9 + 7; 
int mod;
void exgcd(int x, int y, int &a, int &b)  {
	if(y == 0) return a = 1, b = 0, void();
	exgcd(y, x % y, b, a), b -= a * (x / y);
}
int ny(int x) {
	int a, b; exgcd(x, mod, a, b);
	return (a % mod + mod) % mod;
}
int head[N], edge_id;
struct node {
	int to, val, next;
} e[N << 1];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].val = val, e[edge_id].to = v, head[u] = edge_id;
} 
ll ans;
int n, FN, qwq, POW[N], Pow[N], siz[N], dep[N], dis[N], sid[N], rt, rtmax;
bool vis[N];
void findrt(int x, int fa) {
	int maxn = 0; siz[x] = 1;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa || vis[v]) continue;
		findrt(v, x), siz[x] += siz[v];
		maxn = max(maxn, siz[v]);
	} 
	maxn = max(maxn, FN - siz[x]);
	if(maxn < rtmax) rt = x, rtmax = maxn;
}
int Cnt, tot;
map<int, int> A[N], B[N];
priority_queue< pii > q;
void George(int x, int fa) {
	++Cnt, siz[x] = 1;
	A[tot][1ll * (mod - dis[x]) * Pow[dep[x]] % mod] ++, B[tot][sid[x]] ++;
	// cout << "(" << x << ") : " << 1ll * (mod - dis[x]) * Pow[dep[x]] % mod << " " << sid[x] << " qaq : " << dis[x]
	// << " dep : " << dep[x] << endl;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa || vis[v]) continue;
		dep[v] = dep[x] + 1;
		sid[v] = (sid[x] + 1ll * POW[dep[x]] * e[i].val % mod) % mod;
		dis[v] = (10ll * dis[x] % mod + e[i].val) % mod;
		George(v, x), siz[x] += siz[v];
	}
}
void dfz(int x) {
	if(FN == 1) return;
	rtmax = inf, findrt(x, -1), vis[rt] = 1, sid[rt] = dis[rt] = 0, tot = 0;
	// cout << "---------------------------------------------\nrt = " << rt << endl;
	for(int i = head[rt]; i; i = e[i].next) {
		int v = e[i].to;
		if(vis[v]) continue;
		++tot, Cnt = 0, A[tot].clear(), B[tot].clear();
		dep[v] = 1, dis[v] = sid[v] = e[i].val % mod;
		George(v, -1), q.push(mkp(Cnt, tot));
		// cout << "----------------\n";
	}
	++tot, A[tot].clear(), B[tot].clear(), A[tot][0] = 1, B[tot][0] = 1, q.push(mkp(1, tot));
	// cout << "(" << rt << ")0 0\n---------------\n";
	while(q.size() > 1) {
		int p1, p2, sum = 0;
		p1 = q.top().second, sum += q.top().first, q.pop();
		p2 = q.top().second, sum += q.top().first, q.pop();
		for(pii x : A[p2]) ans += 1ll * B[p1][x.first] * x.second;
		for(pii x : A[p1]) ans += 1ll * B[p2][x.first] * x.second;
		
		for(pii x : A[p2]) A[p1][x.first] += x.second;
		for(pii x : B[p2]) B[p1][x.first] += x.second;
		q.push(mkp(sum, p1));
	}
	q.pop();
	// cout << "ans =  " << ans << endl;
	for(int i = head[rt]; i; i = e[i].next) {
		int v = e[i].to;
		if(!vis[v]) FN = siz[v], dfz(v);
	}
} 
int main() {
	scanf("%d%d", &n, &mod);
	qwq = ny(10), POW[0] = Pow[0] = 1;
	L(i, 1, n) POW[i] = 10ll * POW[i - 1] % mod, Pow[i] = 1ll * Pow[i - 1] * qwq % mod;
	L(i, 1, n - 1) {
		int u, v, val; scanf("%d%d%d", &u, &v, &val), ++u, ++v;
		add_edge(u, v, val), add_edge(v, u, val);
	}
	FN = n, dfz(1);
	printf("%lld\n", ans);
	return 0;
}
/*
Pow[dep] * x + d = 0;
x = - \frac{d}{Pow[dep]}
*/