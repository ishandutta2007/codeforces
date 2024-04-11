#include <bits/stdc++.h>
#define il inline
#define ri register int
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define mid ((l+r)>>1)
#define MAXN 500050
#define MAXM
#define MOD
#define INF (1<<25)
#define eps (1e-6)
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair <int, int> pii;
typedef pair <LL, int> pli;
typedef pair <int, LL> pil;
typedef pair <LL, LL> pll;
int n, m, rt[MAXN], tcnt, tot;
struct node {
	int ls, rs, size;
}t[MAXN<<6];
struct onode {
	int u, v, w;
}opt[MAXN<<2];
set <pii> se;
void ins(int &u, int l, int r, int x, int w) {
	if(!u) u = ++tcnt;
	t[u].size += w;
	if(l == r) return ;
	if(x <= mid) ins(t[u].ls, l, mid, x, w);
	else ins(t[u].rs, mid+1, r, x, w);
}
int find(int u, int p, int l, int r) {
	if(l == r) return l;
	if(t[t[u].ls].size > t[t[p].ls].size) return find(t[u].ls, t[p].ls, l, mid);
	return find(t[u].rs, t[p].rs, mid+1, r);
}
int main() {
	int k, w;
	scanf("%d%d", &n, &m);
	for(ri i = 1; i <= n; ++i) {
		scanf("%d", &k);
		for(ri j = 1; j <= k; ++j) {
			scanf("%d", &w);
			ins(rt[i], 1, m, w, 1);
		}
	}
	for(int i = 1; i <= n; ++i) se.insert(mp(t[rt[i]].size, i));
	while(1) {
		pii sm = *se.begin(), bg = *--se.end();
		if(bg.fir < sm.fir+2) break;
		se.erase(sm), se.erase(bg);
		int cur = find(rt[bg.sec], rt[sm.sec], 1, m);
		ins(rt[bg.sec], 1, m, cur, -1), ins(rt[sm.sec], 1, m, cur, 1);
		opt[++tot] = onode {bg.sec, sm.sec, cur};
		se.insert(mp(t[rt[bg.sec]].size, bg.sec)), se.insert(mp(t[rt[sm.sec]].size, sm.sec));
	}
	cout<<tot<<endl;
	for(ri i = 1; i <= tot; ++i) cout<<opt[i].u<<' '<<opt[i].v<<' '<<opt[i].w<<endl;
	return 0;
}