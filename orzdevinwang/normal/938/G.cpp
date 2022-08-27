// George1123 /qiang, SegmentTree /no 
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
struct UFS {
	stack<pii> stk;
	int f[N], siz[N], dis[N];
	void init(int x) { L(i, 1, x) siz[i] = 1, f[i] = i, dis[i] = 0; }
	int find(int x) { return f[x] == x ? x : find(f[x]); }
	int getsum(int x) { return f[x] == x ? 0 : getsum(f[x]) ^ dis[x]; }
	int Merge(int x, int y, int len) {
		while(x ^ f[x]) len ^= dis[x], x = f[x];
		while(y ^ f[y]) len ^= dis[y], y = f[y];
		// x = find(x), y = find(y);
		if(x == y) return 0;
		if(siz[x] > siz[y]) swap(x, y);
		stk.push(mkp(x, siz[x])), f[x] = y, dis[x] = len, siz[y] += siz[x];
		return 1;
	}
	void revoke() {
		int u = stk.top().first;
		siz[f[u]] -= stk.top().second, f[u] = u, stk.pop();
	}
} ufs;
int G[N << 2][30];
void Ins(int id, int x) {
	R(i, 29, 0) if((x >> i) & 1) {
		if(!G[id][i]) G[id][i] = x;
		x ^= G[id][i];
	}
}
int get(int id, int x) {
	// cout << "is : " << x << endl;
	R(i, 29, 0) if((x ^ G[id][i]) < x) x ^= G[id][i];
	return x;
}
void copy(int x, int y) {
	L(i, 0, 29) G[y][i] = G[x][i];
}
int n, m, q, tot, FR[N], TO[N];
struct node {
	int u, v, l, r, val;
} e[N << 1];
vector<int> ve[N << 2];
void ins(int id, int L, int R, int l, int r, int val) {
	if(l <= L && R <= r) return ve[id].push_back(val), void();
	int mid = (L + R) / 2;
	if(l <= mid) ins(id << 1, L, mid, l, r, val); 
	if(r > mid) ins(id << 1 | 1, mid + 1, R, l, r, val);
}
void dfs(int id, int L, int R) {
	// cout << id << " : " << L << " " << R << endl;
	int mid = (L + R) / 2, cnt = 0;
	for(int p : ve[id]) {
		int u = e[p].u, v = e[p].v;
		if(ufs.find(u) == ufs.find(v)) Ins(id, ufs.getsum(u) ^ ufs.getsum(v) ^ e[p].val); 
		else cnt += ufs.Merge(u, v, e[p].val);
	}
	if(L ^ R) copy(id, id << 1), copy(id, id << 1 | 1), dfs(id << 1, L, mid), dfs(id << 1 | 1, mid + 1, R);
	else if(FR[L] && TO[L]) printf("%d\n", get(id, ufs.getsum(FR[L]) ^ ufs.getsum(TO[L])));
	while(cnt--) ufs.revoke();
}
unordered_map<int, int> mp[N];
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, m) {
		++tot;
		scanf("%d%d%d", &e[tot].u, &e[tot].v, &e[tot].val), e[tot].l = 1;
		mp[e[tot].u][e[tot].v] = mp[e[tot].v][e[tot].u] = i;
	}
	scanf("%d", &q);
	L(i, 1, q) {
		int opt, u, v, val;
		scanf("%d%d%d", &opt, &u, &v);
		if(opt == 1) ++tot, scanf("%d", &e[tot].val), mp[u][v] = mp[v][u] = tot, e[tot].u = u, e[tot].v = v, e[tot].l = i;
		if(opt == 2) e[mp[u][v]].r = i, mp[u].erase(v), mp[v].erase(u);
		if(opt == 3) FR[i] = u, TO[i] = v;
	}
	L(i, 1, tot) if(!e[i].r) e[i].r = q;
	L(i, 1, tot) ins(1, 1, q, e[i].l, e[i].r, i);//, cout << e[i].l << " to " << e[i].r << endl;
	ufs.init(n);
	dfs(1, 1, q);
	return 0;
}