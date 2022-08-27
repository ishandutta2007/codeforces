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
int head[N], edge_id;
set<int> e[N];
int n, f[N], tot, FN, siz[N], rt1, rt2;
int vis[N];
void findrt1(int x, int fa) {
	siz[x] = 1;
	for(int v : e[x]) if(v ^ fa) findrt1(v, x), siz[x] += siz[v];
	if(siz[x] == f[FN - 1]) rt1 = x, rt2 = fa;
}
void findrt2(int x, int fa) {
	for(int v : e[x]) if(v ^ fa) findrt2(v, x);
	if(siz[x] == f[FN - 2]) rt1 = x, rt2 = fa;
}
void divide(int x) {
	if(FN <= 2) return;
	bool ok = 1;
	rt1 = rt2 = -1, findrt1(x, -1);
	if(rt1 == -1) {
		findrt2(x, -1);
		if(rt1 == -1) cout << "NO\n", exit(0);
		ok = 0;
	}
	int DEP = FN, RT1 = rt1, RT2 = rt2;
	e[rt1].erase(rt2), e[rt2].erase(rt1);
	if(ok) FN = DEP - 1, divide(RT1), FN = DEP - 2, divide(RT2);
	else FN = DEP - 2, divide(RT1), FN = DEP - 1, divide(RT2);
} 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	f[0] = 1, f[1] = 1, vis[0] = true, tot = 1;
	while(f[tot] <= n) vis[f[tot]] = tot, ++tot, f[tot] = f[tot - 1] + f[tot - 2];
	--tot;
	if(!vis[n]) cout << "NO\n", exit(0);
	L(i, 1, n - 1) {
		int u, v; 
		cin >> u >> v;
		e[u].insert(v), e[v].insert(u);
	}
	FN = vis[n], divide(1);
	cout << "YES\n";
	return 0;
}