#include<bits/stdc++.h>
#define N 210000
#define M 510000
using namespace std;
int lowbit(int x) {return x & -x;}
int n, Q, ans[N], ch[N][26], fa[N], fail[N], tot, uid[N], siz[N], cnt;
long long szsz[N];
void add(int x, int val) {
	if(x == 0) return;
	while(x <= cnt) szsz[x] += val,x += lowbit(x);
//	for(int i = x; i <= cnt; i += lowbit(x)) szsz[i] += val;
}
int qzh(int x) {
	int Ans = 0;
	for(int i = x; i; i -= lowbit(i)) Ans += szsz[i];
	return Ans;
}
int head[N], last[N];
struct node {
	int to, next;
} e[N];
int edge_id;
void add_edge(int u, int v) {
	++edge_id;
	if(!head[u]) head[u] = edge_id;
	else e[last[u]].next = edge_id;
	e[edge_id].to = v, last[u] = edge_id;
}
void ins(char *f, int len, int id) {
	int now = 0;
	for(int i = 0; i < len; i++) {
		if(!ch[now][f[i] - 'a']) ch[now][f[i] - 'a'] = ++tot, fa[tot] = now;
		now = ch[now][f[i] - 'a'];
	}
	ans[id] = now;
}
void bfs() {
	queue<int> q; 
	for(int i = 0; i < 26; i++) if(ch[0][i]) q.push(ch[0][i]);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < 26; i++) {
			int v = ch[u][i];
			if(!v) ch[u][i] = ch[fail[u]][i];
			else fail[v] = ch[fail[u]][i], q.push(v);
		}
	}
}
void dfs(int x) {
	uid[x] = ++cnt, siz[x] = 1;
	for(int i = head[x]; i; i = e[i].next) dfs(e[i].to), siz[x] += siz[e[i].to];
} 
void build() {
	for(int i = 1; i <= tot; i++) add_edge(fail[i], i);
	dfs(0);
} 
struct ask {
	int x, cx, id, flag;
	long long ans;
} q[M << 1];
bool cmp(ask aa, ask bb) {
	return aa.x < bb.x;
}
bool pmc(ask aa, ask bb) {
	return aa.id == bb.id ? aa.flag < bb.flag : aa.id < bb.id; 
}
char s[N];
int main() {
	scanf("%d%d", &n, &Q);
	for(int i = 1; i <= n; i++) {
		scanf("%s", s);
		ins(s, strlen(s), i);
	}
	bfs(), build();
	for(int i = 1; i <= Q; i++) {
		scanf("%d", &q[i * 2 - 1].x), q[i * 2 - 1].x--;
		scanf("%d", &q[i * 2].x);
		scanf("%d", &q[i * 2].cx), q[i * 2 - 1].cx = q[i * 2].cx;
		q[i * 2 - 1].id = q[i * 2].id = i;
		q[i * 2 - 1].flag = -1, q[i * 2].flag = 1;
	}
	sort(q + 1, q + 2 * Q + 1, cmp);
	int xyx = 1;
	while(q[xyx].x == 0) ++xyx;
	for(int i = 1; i <= n; ++i) {
		for(int j = ans[i]; j; j = fa[j]) add(uid[j], 1);
		while(q[xyx].x == i) {
			int ques = ans[q[xyx].cx], pid = uid[ques];
			q[xyx].ans = qzh(pid + siz[ques] - 1) - qzh(pid - 1);
			++xyx;
		}
	}
	sort(q + 1, q + 2 * Q + 1, pmc);
	for(int i = 1; i <= Q; i++) printf("%lld\n", q[i * 2].ans - q[i * 2 - 1].ans);
	return 0;
}