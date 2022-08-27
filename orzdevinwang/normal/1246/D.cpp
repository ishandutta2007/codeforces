#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e6 + 7;
int n, fa[N], mxd[N], hv[N], cc[N], tp;
vi e[N];
void dfs1 (int x) {
	for (const int &v : e[x]) {
		dfs1 (v);
		if(mxd[v] + 1 > mxd[x]) hv[x] = v, mxd[x] = mxd[v] + 1;
	}
}
void dfs2 (int x, int lk) {
	if(lk) hv[x] = 0, cc[++tp] = lk;
	else lk = hv[x];
	for (const int &v : e[x]) if(v != hv[x]) dfs2 (v, lk), lk = v;
	if(hv[x]) dfs2(hv[x], 0);
}
void dfs3 (int x, int lk) {
	cout << x << ' ';
	R(i, sz(e[x]) - 1, 0) if(e[x][i] != hv[x]) dfs3(e[x][i], true);
	if(hv[x]) dfs3(hv[x], false);
}
int main () {
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
	L(i, 1, n - 1) cin >> fa[i];
	L(i, 1, n - 1) e[fa[i]].push_back(i);
	dfs1 (0), dfs2 (0, 0), dfs3(0, 0);
    cout << '\n' << tp << '\n';
    R(i, tp, 1) cout << cc[i] << ' ';
    cout << '\n';
	return 0;
}