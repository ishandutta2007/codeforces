#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define eb emplace_back

using namespace std;

const int N = 3e5 + 5;

int n, m, x, vis[N], as[N], L, R;
long long a[N], su;
vector <pair <int, int>> G[N];

void dfs(int u) {
	vis[u] = 1;
	for(auto [v, i] : G[u]) if(!vis[v])
		dfs(v), a[v] >= 0 ? a[u] += a[v], as[L++] = i : as[R--] = i;
}
int main() {
	cin >> n >> m >> x;
	rep(i, 1, n) scanf("%lld", &a[i]), su += a[i] -= x;
	int u, v;
	rep(i, 1, m) scanf("%d%d", &u, &v), G[u].eb(v, i), G[v].eb(u, i);
	if(su + x < 0) puts("NO"), exit(0);
	puts("YES"), L = 2, R = n, dfs(1);
	rep(i, 2, n) printf("%d\n", as[i]);
	return 0;
}