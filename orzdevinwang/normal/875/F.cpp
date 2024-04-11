#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e5 + 7;
int n, m, f[N], vis[N], ans;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
struct edge { int u, v, w; } e[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) f[i] = i;
	L(i, 1, m) cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1, e + m + 1, [&] (edge aa, edge bb) { return aa.w > bb.w; });
	L(i, 1, m) 
		if(find(e[i].u) != find(e[i].v) && (! vis[find(e[i].u)] || ! vis[find(e[i].v)])) ans += e[i].w, vis[find(e[i].v)] |= vis[find(e[i].u)], f[find(e[i].u)] = find(e[i].v);
		else if(!vis[find(e[i].u)]) ans += e[i].w, vis[find(e[i].u)] = true;
	cout << ans << "\n";
	return 0;
}