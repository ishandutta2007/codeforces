// [*easy]
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
int n, m, q, f[N], siz[N], tmp[N << 1], *id = tmp, r[N]; 
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
vector<int> e[N];
int *cnt[N], nrt, l[N], maxn[N], cmax[N]; ll *Sum[N], ttmp[N << 1], *tid = ttmp;
void dfs1(int x, int fa) {
	for(int v : e[x]) if(v ^ fa) {
		dfs1(v, x);
		if(maxn[v] + 1 > maxn[x]) cmax[x] = maxn[x], maxn[x] = maxn[v] + 1;
		else if(maxn[v] + 1 > cmax[x]) cmax[x] = maxn[v] + 1;
	}
}
void dfs2(int x, int fa, int now) {
	if(now > maxn[x]) cmax[x] = maxn[x], maxn[x] = now;
	else if(now > cmax[x]) cmax[x] = now;
	l[x] = maxn[x], r[nrt] = max(r[nrt], l[x]);
	cnt[nrt][l[x]] ++;
	Sum[nrt][l[x]] += l[x];
	for(int v : e[x]) if(v ^ fa) {
		if(maxn[v] + 1 == maxn[x]) dfs2(v, x, cmax[x] + 1); 
		else dfs2(v, x, maxn[x] + 1);
	}
}
map<int, ll> mp[N];
ll work(int u, int v) {
	if(mp[u].count(v)) return mp[u][v];
	ll res = 0; int T = max(r[u], r[v]) - 1;
	L(i, 0, siz[u] - 1) {
		int dd = cnt[u][i] - (i ? cnt[u][i - 1] : 0), Cnt = 0; ll Val = 0; 
		if(T >= i) Cnt = cnt[v][T - i], Val = Sum[v][T - i];
		res += 1ll * dd * Cnt * T;
		res += 1ll * dd * (Sum[v][siz[v] - 1] - Val);
		res += 1ll * dd * (siz[v] - Cnt) * i;
	}
	return mp[u][v] = res;
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	L(i, 1, n) siz[i] = 1, f[i] = i;
	L(i, 1, m) {
		int u, v; scanf("%d%d", &u, &v);
		e[u].push_back(v), e[v].push_back(u);
		siz[find(v)] += siz[find(u)], siz[find(u)] = 0, f[find(u)] = find(v);
	}
	L(i, 1, n) if(find(i) == i) {
		nrt = i, cnt[i] = id, Sum[i] = tid, id += siz[i] + 1, tid += siz[i] + 1;
		dfs1(i, -1), dfs2(i, -1, 0);
		L(j, 1, siz[i] - 1) cnt[nrt][j] += cnt[nrt][j - 1];
		L(j, 1, siz[i] - 1) Sum[nrt][j] += Sum[nrt][j - 1];
	}
	while(q--) {
		int u, v; scanf("%d%d", &u, &v);
		u = find(u), v = find(v);
		if(u == v) {
			puts("-1");
			continue;
		}
		if(siz[u] > siz[v]) swap(u, v);
		printf("%.10lf\n", 1. * work(u, v) / (1ll * siz[u] * siz[v]) + 1);
	}
	return 0;
}