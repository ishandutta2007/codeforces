#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e5 + 7;
const int B = 300;
int n, m, len[N], q[N], l[N], r[N], wz[N], ch[N][26], fa[N], tot = 1, id[N], siz[N], idtot;
ll ans[N], qz[N];
int sz[N];
void clear() {
	L(i, 1, tot) sz[i] = 0;
}
void add(int x, int y) {
	for(; x <= tot; x += (x & -x)) sz[x] += y;
}
int qzh(int x) {
	int res = 0;
	for(; x; x -= (x & -x)) res += sz[x];
	return res;
}
vector<int> chs[N], ask[N]; 
vector<pii> ve[N];
void insert(char *s, int L, int id) {
	int now = 1;
	L(i, 0, L - 1) {
		if(!ch[now][s[i] - 'a']) ch[now][s[i] - 'a'] = ++tot;
		now = ch[now][s[i] - 'a'];
		chs[id].push_back(now);
	} 
	wz[id] = now, len[id] = L; 
}
int head[N], edge_id;
struct node {
	int to, next;
} e[N];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
void build() {
	queue<int> q;
	L(i, 0, 25) {
		if(ch[1][i]) fa[ch[1][i]] = 1, q.push(ch[1][i]);
		else ch[1][i] = 1;
	}
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		L(i, 0, 25) {
			if(ch[u][i]) fa[ch[u][i]] = ch[fa[u]][i], q.push(ch[u][i]);
			else ch[u][i] = ch[fa[u]][i];
		}
	}
}
void dfs(int x) {
	id[x] = ++idtot, siz[x] = 1;
	for(int i = head[x]; i; i = e[i].next) dfs(e[i].to), siz[x] += siz[e[i].to];
}
char s[N];
int main() {
	scanf("%d%d", &n, &m);
	L(i, 1, n) {
		scanf("%s", s);
		insert(s, strlen(s), i);
	}
	build();
	L(i, 2, tot) add_edge(fa[i], i);
	dfs(1); 
	L(i, 1, m) {
		scanf("%d%d%d", &l[i], &r[i], &q[i]);
		if(len[q[i]] <= B) ve[r[i]].push_back(mkp(i, 1)), ve[l[i] - 1].push_back(mkp(i, -1));
		else ask[q[i]].push_back(i);
	}
	L(i, 1, n) {
		add(id[wz[i]], 1);
		add(id[wz[i]] + siz[wz[i]], -1);
		for(pii x : ve[i]) {
			int askid = x.first;
			for(int p : chs[q[askid]]) ans[askid] += qzh(id[p]) * x.second; 
		}
	}
	L(i, 1, n) if(len[i] > B) {
		clear();
		for(int x : chs[i]) add(id[x], 1);
		L(j, 1, n) qz[j] = qz[j - 1] + qzh(id[wz[j]] + siz[wz[j]] - 1) - qzh(id[wz[j]] - 1);
		for(int x : ask[i]) ans[x] = qz[r[x]] - qz[l[x] - 1]; 
	}
	L(i, 1, m) printf("%lld\n", ans[i]);
	return 0;
}