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
const int M = 3e6 + 7;
int n, l, w;
int head[N], edge_id;
struct node {
	int to, val, next;
} e[N << 1];
void add_edge(int u, int v, int val) {
	++edge_id, e[edge_id].val = val, e[edge_id].to = v, e[edge_id].next = head[u], head[u] = edge_id;
}
int Fn, siz[N], rt, minn, sz[N];
bool vis[N];
void findrt(int x, int fa) {
	siz[x] = 1;
	int minx = 0;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa || vis[v]) continue;
		findrt(v, x);
		siz[x] += siz[v];
		minx = max(minx, siz[v]);
	}
	minx = max(minx, Fn - siz[x]);
	if(minn > minx) minn = minx, rt = x;
}
struct GG { vector<pii> ve; int siz; } now;
bool operator < (GG aa, GG bb) { return aa.siz < bb.siz; }
void dfs(int x, int fa, int val, int len) {
	if(val > w) val = w + 1;
	siz[x] = 1;
	now.ve.push_back(mkp(len, val)), now.siz ++;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa || vis[v]) continue;
		siz[x] += siz[v];
		dfs(v, x, val + e[i].val, len + 1);
	}
}
priority_queue< GG > q;
int hd, sum[M], ch[M][2], totseg;
void upd(int x) { sum[x] = sum[ch[x][0]] + sum[ch[x][1]]; }
void add(int &x, int L, int R, int wz) {
	if(!x) x = ++totseg, sum[x] = ch[x][0] = ch[x][1] = 0;
	sum[x] ++;
	if(L == R) return;
	int mid = (L + R) / 2;
	if(wz <= mid) add(ch[x][0], L, mid, wz);
	else add(ch[x][1], mid + 1, R, wz);
}
int query(int x, int L, int R, int wz) {
	if(!x) return 0;
	if(L == R) return sum[x];
	int mid = (L + R) / 2;
	if(wz <= mid) return query(ch[x][0], L, mid, wz);
	else return sum[ch[x][0]] + query(ch[x][1], mid + 1, R, wz);
}
pii Ma[N], Mb[N]; int tota, totb; ll ans;
void dfz(int x) {
	if(Fn == 1) return;
	minn = 1e9, findrt(x, -1);
	vis[rt] = 1;
	for(int i = head[rt]; i; i = e[i].next) if(!vis[e[i].to]) {
		int v = e[i].to;
		now.ve.clear(), now.siz = 0, dfs(v, rt, e[i].val, 1);
		sort(now.ve.begin(), now.ve.end()), q.push(now);
	}
	now.ve.clear(), now.siz = 1; now.ve.push_back(mkp(0, 0)), q.push(now);
	// cout << "siz = " << q.size() << endl;
	while(q.size() > 1) {
		tota = 0; for(pii x : q.top().ve) Ma[++tota] = x; q.pop();
		// cout << "a : ";
		// L(i, 1, tota) cout << "(" << Ma[i].first << " " << Ma[i].second << ")";
		// puts("");
		totb = 0; for(pii x : q.top().ve) Mb[++totb] = x; q.pop();
		// cout << "b : ";
		// L(i, 1, totb) cout << "(" << Mb[i].first << " " << Mb[i].second << ")";
		// puts("");
		now.ve.clear(), now.siz = 0;
		int nowb = 1;
		totseg = hd = 0;
		R(i, tota, 1) {
			while(nowb <= totb && Ma[i].first + Mb[nowb].first <= l) {
				if(Mb[nowb].second <= w) add(hd, 0, w, Mb[nowb].second);
				++ nowb;
			}
			if(Ma[i].second <= w) ans += query(hd, 0, w, w - Ma[i].second);
		}
		// cout << ans << endl;
		nowb = 1, now.siz = tota + totb;
		L(i, 1, tota) {
			while(nowb <= totb && Mb[nowb].first < Ma[i].first) now.ve.push_back(Mb[nowb]), ++nowb;
			now.ve.push_back(Ma[i]);
		}
		while(nowb <= totb) now.ve.push_back(Mb[nowb]), ++nowb;
		q.push(now);
	}
	while(!q.empty()) q.pop();
	for(int i = head[rt]; i; i = e[i].next) if(!vis[e[i].to]) Fn = siz[e[i].to], dfz(e[i].to);
}
int main() {
	scanf("%d%d%d", &n, &l, &w);
	L(i, 2, n) {
		int p, val; scanf("%d%d", &p, &val);
		add_edge(i, p, val), add_edge(p, i, val);
	}
	Fn = n, dfz(1);
	printf("%lld\n", ans);
	return 0;
}