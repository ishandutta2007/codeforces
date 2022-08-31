#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, a[N], b[N], ehd[N], enx[N], ev[N], eid;
void eadd(int u, int v) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ehd[u] = eid;
}
int col[N];
void dfs(int x) {
	for(int i = ehd[x]; i; i = enx[i]) 
		if(!col[ev[i]]) col[ev[i]] = 3 - col[x], dfs(ev[i]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i] >> b[i], eadd(a[i], b[i]), eadd(b[i], a[i]);
	L(i, 1, n) eadd(i * 2 - 1, i * 2), eadd(i * 2, i * 2 - 1);
	L(i, 1, n * 2) if(!col[i]) col[i] = 1, dfs(i); 
	L(i, 1, n) cout << col[a[i]] << " " << col[b[i]] << "\n";
	return 0;
}