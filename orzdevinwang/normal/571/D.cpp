#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
struct node {
	int n, id[N], idtot, siz[N], l[N], r[N], f[N], tot, ch[N][2];
	int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
	void init(int x) {
		n = tot = x;
		L(i, 1, x << 1) f[i] = i, siz[i] = 1;
	}
	int merge(int x, int y) {
		x = find(x), y = find(y);
		f[x] = f[y] = ++tot, siz[tot] = siz[x] + siz[y], ch[tot][0] = x, ch[tot][1] = y;
		return tot;
	}
	void build(int now) {
		l[now] = idtot + 1;
		if(now <= n) id[now] = ++idtot;
		else build(ch[now][0]), build(ch[now][1]);
		r[now] = idtot;
	}
	void work() {
		L(i, 1, tot) if(f[i] == i) build(i);
	}
} A, B;
int n, m, x[N], y[N], id[N], las[N], val[N << 2];
ll p[N], ans[N];
void Add(int l, int r, int val) {
	--l;
	for(; l; l -= (l & -l)) p[l] -= val;
	for(; r; r -= (r & -r)) p[r] += val;
}
ll Qry(int pos) {
	ll res = 0;
	for(; pos <= n; pos += (pos & -pos)) res += p[pos];
	return res;
}
char opt[N][10];
void add(int id, int L, int R, int l, int r, int w) {
	if(l <= L && R <= r) return val[id] = w, void();
	int mid = (L + R) >> 1;
	if(l <= mid) add(id << 1, L, mid, l, r, w);
	if(r > mid) add(id << 1 | 1, mid + 1, R, l, r, w);
}
int qry(int id, int L, int R, int pos) {
	if(L == R) return val[id];
	int mid = (L + R) >> 1;
	if(pos <= mid) return max(val[id], qry(id << 1, L, mid, pos));
	else return max(val[id], qry(id << 1 | 1, mid + 1, R, pos));
}
vector< int > ve[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	A.init(n), B.init(n);
	L(i, 1, m) { 
		cin >> (opt[i] + 1) >> x[i];
		if(opt[i][1] == 'U') cin >> y[i], id[i] = A.merge(x[i], y[i]);
		if(opt[i][1] == 'M') cin >> y[i], id[i] = B.merge(x[i], y[i]);
		if(opt[i][1] == 'A') id[i] = A.find(x[i]);
		if(opt[i][1] == 'Z') id[i] = B.find(x[i]);
	}
	A.work(), B.work();
	L(i, 1, m) 
		if(opt[i][1] == 'Z') add(1, 1, n, B.l[id[i]], B.r[id[i]], i); 
		else if(opt[i][1] == 'Q') ve[qry(1, 1, n, B.id[x[i]])].push_back(i);
	L(i, 1, m) {
		if(opt[i][1] == 'A') Add(A.l[id[i]], A.r[id[i]], A.siz[id[i]]);
		if(opt[i][1] == 'Q') ans[i] += Qry(A.id[x[i]]);
		L(j, 0, ve[i].size() - 1) ans[ve[i][j]] -= Qry(A.id[x[ve[i][j]]]);
	}
	L(i, 1, m) if(opt[i][1] == 'Q') cout << ans[i] << "\n";
	return 0;
}