// #pragma GCC optimize(3)
// #pragma GCC target("avx,sse2,sse3,sse4,mmx")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("-falign-jumps")
// #pragma GCC optimize("-falign-loops")
// #pragma GCC optimize("-falign-labels")
// #pragma GCC optimize("-fdevirtualize")
// #pragma GCC optimize("-fcaller-saves")
// #pragma GCC optimize("-fcrossjumping")
// #pragma GCC optimize("-fthread-jumps")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-fwhole-program")
// #pragma GCC optimize("-freorder-blocks")
// #pragma GCC optimize("-fschedule-insns")
// #pragma GCC optimize("inline-functions")
// #pragma GCC optimize("-ftree-tail-merge")
// #pragma GCC optimize("-fschedule-insns2")
// #pragma GCC optimize("-fstrict-aliasing")
// #pragma GCC optimize("-fstrict-overflow")
// #pragma GCC optimize("-falign-functions")
// #pragma GCC optimize("-fcse-skip-blocks")
// #pragma GCC optimize("-fcse-follow-jumps")
// #pragma GCC optimize("-fsched-interblock")
// #pragma GCC optimize("-fpartial-inlining")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("-freorder-functions")
// #pragma GCC optimize("-findirect-inlining")
// #pragma GCC optimize("-fhoist-adjacent-loads")
// #pragma GCC optimize("-frerun-cse-after-loop")
// #pragma GCC optimize("inline-small-functions")
// #pragma GCC optimize("-finline-small-functions")
// #pragma GCC optimize("-ftree-switch-conversion")
// #pragma GCC optimize("-foptimize-sibling-calls")
// #pragma GCC optimize("-fexpensive-optimizations")
// #pragma GCC optimize("-funsafe-loop-optimizations")
// #pragma GCC optimize("inline-functions-called-once")
// #pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
// char buf[1<<23], *p1 = buf, *p2 = buf, obuf[1<<23], *O = obuf;
// #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch= getchar();
	return x * f;
}
const int N = 4e5 + 7;
const int M = N * 12;
ll pwz[N];
struct SegmentTree {
	int lz[N << 2]; 
	ll sum[N << 2];
	int sizl, sizr;
	void AD(int id, int L, int R, int val) {
		lz[id] += val, sum[id] += (pwz[R] - pwz[L - 1]) * val;
	}
	void pushdown(int id, int L, int R) {
		if(!lz[id]) return;
		int mid = (L + R) >> 1; 
		AD(id << 1, L, mid, lz[id]), AD(id << 1 | 1, mid + 1, R, lz[id]), lz[id] = 0;
	}
	void upd(int id) {
		sum[id] = sum[id << 1] + sum[id << 1 | 1];
	}
	void Add(int id, int L, int R, int l, int r, int val) {
		if(l <= L && R <= r) return AD(id, L, R, val);
		int mid = (L + R) >> 1, res = 0;
		pushdown(id, L, R);
		if(l <= mid) Add(id << 1, L, mid, l, r, val);
		if(r > mid) Add(id << 1 | 1, mid + 1, R, l, r, val);
		upd(id);
	}
	ll query(int id, int L, int R, int l, int r) {
		if(l <= L && R <= r) return sum[id];
		int mid = (L + R) >> 1; ll res = 0;
		pushdown(id, L, R);
		if(l <= mid) res += query(id << 1, L, mid, l, r);
		if(r > mid) res += query(id << 1 | 1, mid + 1, R, l, r);
		return res;
	}
	void add(int L, int R, int val) { Add(1, sizl, sizr, L, R, val); }
	ll qry(int L, int R) { return query(1, sizl, sizr, L, R); }
} segA;
ll ans[N];
int n, m, ch[N][26], len[N], fa[N], sign[N], las = 1, tot = 1;
void copy(int x,int y){
	L(i, 0, 25) ch[y][i] = ch[x][i];
	fa[y] = fa[x], len[y] = len[x];
}
void ins(int x, int y) {
	int p = las, now = las = ++tot;
	len[now] = len[p] + 1, sign[now] = y; 
	for(; p && !ch[p][x]; p = fa[p]) ch[p][x] = now; 
	if(!p) fa[now] = 1; 
	else {
		int pto = ch[p][x];
		if(len[pto] == len[p] + 1) fa[now] = pto;
		else{
			int sp = ++tot;
			copy(pto, sp), len[sp] = len[p] + 1;
			fa[now] = fa[pto] = sp;
			for(; p && ch[p][x] == pto; p = fa[p]) ch[p][x] = sp;
		}
	}
}
ll arr[M]; int atot;
struct FenWick {
	ll val[M];
	void add(int now, ll v) {
		for(; now <= atot; now += (now & -now)) val[now] += v;
	}
	ll qzh(int now) {
		ll res = 0;
		for(; now; now -= (now & -now)) res += val[now];
		return res;
	}
	void clear() { L(i, 1, atot) val[i] = 0; }
} BalB, BalC;
char s[N];
int l[N], r[N], pos[N], sv[N];
int ftot, gtot;
struct askf {
	ll X; int Y, buf;
} f[M];
struct askg {
	ll X; int Y, id, buf;
} g[M];
vector< int > ask1[N], e[N];
int dep[N], hv[N], siz[N], id[N], mp[N], idtot, maxto[N];
void dfs1(int x) {
	siz[x] = 1;
	for(int v : e[x]) {
		dep[v] = dep[x] + 1, dfs1(v), siz[x] += siz[v];
		if(siz[hv[x]] < siz[v]) hv[x] = v;
	}
}
void dfs2(int x) {
	id[x] = ++idtot, mp[idtot] = x;
	pwz[idtot] = pwz[idtot - 1] + len[x] - len[fa[x]]; 
	if(hv[x]) maxto[hv[x]] = maxto[x], dfs2(hv[x]);
	for(int v : e[x]) if(v ^ hv[x]) maxto[v] = v, dfs2(v);
}
int up[20][N];
int UP(int l, int r) {
	int now = pos[l];
	R(i, 19, 0) if(len[up[i][now]] >= r - l + 1) now = up[i][now];
	return now;
}
void adda(int x, int val) {
	for(; x; x = fa[maxto[x]]) segA.add(id[maxto[x]], id[x], val);
}
ll querya(int x, int Len) {
	if(x == 0) return 0;
	ll res = 0;
	res += 1ll * segA.qry(id[x], id[x]) / (len[x] - len[fa[x]]) * (Len - len[fa[x]]), x = fa[x];
	for(; x; x = fa[maxto[x]]) res += segA.qry(id[maxto[x]], id[x]);
	return res;
}
void worka() {
	L(i, 1, n) {
		adda(pos[i], 1);
		for(int x : ask1[i]) ans[x] -= querya(sv[x], r[x] - l[x] + 1);
	}
}
void addb1(int x) {
	for(int now = pos[x]; now; now = fa[maxto[now]]) {
		if(len[fa[maxto[now]]] + x <= n)
			++ftot, f[ftot].X = pwz[id[maxto[now]] - 1] + 1, f[ftot].Y = len[fa[maxto[now]]] + 1 + x, f[ftot].buf = 1, 
			arr[++atot] = f[ftot].X - f[ftot].Y;
		if(len[now] + x <= n)
			++ftot, f[ftot].X = pwz[id[now]] + 1, f[ftot].Y = len[now] + 1 + x, f[ftot].buf = -1, 
			arr[++atot] = f[ftot].X - f[ftot].Y;
	}
}
int findwz(ll x) { return upper_bound(arr + 1, arr + atot + 1, x) - arr - 1; }
// x  : 4e10   y  : 4e5
void addb2(ll x, int y, int val) {
	int gg = findwz(x - y);
	BalB.add(gg, val), BalC.add(gg, val * y);
}
ll queryb2(ll x, int y) { 
	int gg = findwz(x - y - 1);
	return BalB.qzh(gg) * (y + 1) - BalC.qzh(gg);
}
int tmp; ll sum;
void addb3(ll x, int y, int val) {
	int gg = findwz(x - y);
	BalB.add(gg, val), BalC.add(gg, val * x), tmp += val, sum += val * x;
}
ll queryb3(ll x, int y) { 
	int gg = findwz(x - y - 1);
	return (tmp - BalB.qzh(gg)) * (x + 1) - (sum - BalC.qzh(gg));
}
void queryb1(int x, int Len) {
	int now = sv[x];
	++gtot, g[gtot].buf = 1, g[gtot].X = pwz[id[now]] - (len[now] - Len), g[gtot].Y = r[x] + 1, g[gtot].id = x;
	++gtot, g[gtot].buf = -1, g[gtot].X = pwz[id[now] - 1], g[gtot].Y = r[x] + 1, g[gtot].id = x;
	now = fa[now];
	for(; now; now = fa[maxto[now]]) {
		++gtot, g[gtot].buf = 1, g[gtot].X = pwz[id[now]], g[gtot].Y = r[x] + 1, g[gtot].id = x;
		++gtot, g[gtot].buf = -1, g[gtot].X = pwz[id[maxto[now]] - 1], g[gtot].Y = r[x] + 1, g[gtot].id = x;
	}
}
void workb() {
	L(i, 1, n) addb1(i);
	L(i, 1, m) queryb1(i, r[i] - l[i] + 1);
	
	sort(arr + 1, arr + atot + 1);
	atot = unique(arr + 1, arr + atot + 1) - arr - 1;

	sort(f + 1, f + ftot + 1, [&](askf aa, askf bb) { return aa.Y < bb.Y; });
	sort(g + 1, g + gtot + 1, [&](askg aa, askg bb) { return aa.Y < bb.Y; });
	int now = 0;
	L(t, 1, gtot) {
		while(now <= ftot && f[now + 1].Y <= g[t].Y) ++now, addb2(f[now].X, f[now].Y, f[now].buf);
		ans[g[t].id] += g[t].buf * queryb2(g[t].X, g[t].Y);
	}
	BalB.clear(), BalC.clear();
	
	sort(f + 1, f + ftot + 1, [&](askf aa, askf bb) { return aa.X < bb.X; });
	sort(g + 1, g + gtot + 1, [&](askg aa, askg bb) { return aa.X < bb.X; });
	now = 0;
	L(t, 1, gtot) {
		while(now <= ftot && f[now + 1].X <= g[t].X) ++now, addb3(f[now].X, f[now].Y, f[now].buf);
		ans[g[t].id] += g[t].buf * queryb3(g[t].X, g[t].Y);
	}
}
int main(){
	scanf("%s", s + 1), n = strlen(s + 1);
	R(i, n, 1) ins(s[i] - 'a', i), pos[i] = las;
	m = read();
	L(i, 1, m) l[i] = read(), r[i] = read();
	// cout << "end read -------------------------------------------\n";
	L(i, 2, tot) e[fa[i]].push_back(i)/* , cout << fa[i] << " " << i << endl */, up[0][i] = fa[i];
	L(i, 1, 18) L(j, 1, tot) up[i][j] = up[i - 1][up[i - 1][j]];
	dfs1(1), maxto[1] = 1, dfs2(1);
	segA.sizl = 1, segA.sizr = tot;
	L(i, 1, m) sv[i] = UP(l[i], r[i]), ask1[l[i] - 1].push_back(i);
	worka();
	workb();
	L(i, 1, m) printf("%lld\n", ans[i]);
	return 0;
}