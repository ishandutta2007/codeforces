#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 5e6;
int n, m;
vi e[N], vc[N];
ll All;
char s[N];
struct query {
	int op;
	ll a, b;
	bool ns;
} q[N >> 5]; 
int f[N];
int find (int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
ll sl[N];
int len[N];
bool vis[N];
int rt, tag[N], ch[N][2], tot;
void pushdown(int x) {
	if(!ch[x][0]) ch[x][0] = ++tot;
	if(!ch[x][1]) ch[x][1] = ++tot;
	if(tag[x]) tag[ch[x][0]] = tag[ch[x][1]] = tag[x], tag[x] = 0;
}
void add (int x, ll L, ll R, ll l, ll r, ll W) {
	if(l <= L && R <= r) return tag[x] = W, void();
	ll mid = (L + R) >> 1;
	pushdown(x);
	if(l <= mid) add (ch[x][0], L, mid, l, r, W);
	if(r > mid) add (ch[x][1], mid + 1, R, l, r, W);
}
void DFS (int x, ll L, ll R, int dep) {
	if(!ch[x][0] && !ch[x][1]) {
		vis[x] = true;
		sl[x] = L;
		len[x] = dep;
		vc[tag[x]].push_back(x);
		return ;
	}
	pushdown(x);
	ll mid = (L + R) >> 1;
	DFS(ch[x][0], L, mid, dep - 1), DFS(ch[x][1], mid + 1, R, dep - 1);
}
int getid (int x, ll L, ll R, ll p) {
	if(!ch[x][0] && !ch[x][1]) 
		return x;
	ll mid = (L + R) >> 1;
	if(p <= mid) return getid(ch[x][0], L, mid, p);
	else return getid(ch[x][1], mid + 1, R, p);
}
void eadd (int u, int v) {
	if(tag[u] < tag[v]) e[u].push_back(v);
	else e[v].push_back(u);
}
void Merge (int x, int y) {
	if(vis[x] && vis[y]) return eadd (x, y);
	if(vis[y]) swap(x, y);
	if(vis[x]) 
		Merge (x, ch[y][0]), Merge(x, ch[y][1]);
	else 
		Merge (ch[x][0], ch[y][0]), Merge(ch[x][1], ch[y][1]);
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m, All = 1LL << n;
	rt = ++tot, tag[rt] = m + 1;
	L(i, 1, m) {
		cin >> (s + 1);
		q[i].op = s[1] == 'b' ? 1 : 2;
		cin >> q[i].a >> q[i].b;
	}
	R(i, m, 1) if(q[i].op == 1) add(1, 0, All - 1, q[i].a, q[i].b, i);
	DFS(1, 0, All - 1, n);
	L(i, 1, tot) if(!vis[i]) Merge(ch[i][0], ch[i][1]);
	L(i, 1, tot) f[i] = i;
	for(const int &u : vc[m + 1])
		for(const int &v : e[u]) {
			int x = find(u), y = find(v);
			if(x != y) f[x] = y;
		}
	R(i, m, 1) {
		if(q[i].op == 1) {
			for(const int &u : vc[i])
				for(const int &v : e[u]) {
					int x = find(u), y = find(v);
					if(x != y) f[x] = y;
				}
		}
		else {
			int u = getid(1, 0, All - 1, q[i].a), v = getid(1, 0, All - 1, q[i].b);
			q[i].ns = find(u) == find(v);
		}
	}
	L(i, 1, m) if(q[i].op == 2) cout << q[i].ns << "\n";
	return 0;
}