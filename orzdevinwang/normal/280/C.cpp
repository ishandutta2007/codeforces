#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 5e5 + 7, inf = 1e9;
int n;
int ehd[N], ev[N], enx[N], eid, dep[N];
double ns = 0;
void eadd(int u, int v) {
	++eid, enx[eid] = ehd[u], ev[eid] = v, ehd[u] = eid;
}
void dfs(int x, int fa) {
	ns += 1. / dep[x];
	for(int i = ehd[x]; i; i = enx[i]) if(ev[i] != fa) dep[ev[i]] = dep[x] + 1, dfs(ev[i], x);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		eadd(u, v), eadd(v, u);
	}
	dep[1] = 1, dfs(1, 0), cout.precision(12), cout << fixed, cout << ns << "\n";
	return 0;
}