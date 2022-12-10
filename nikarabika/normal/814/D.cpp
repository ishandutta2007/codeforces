//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const LD PI = 3.14159265358;
const int maxn = 1000 + 10;
LL r[maxn],
   x[maxn],
   y[maxn];
int h[maxn],
	par[maxn];
LD dp[maxn][2];
int n;

LL sqr(LL x) {return x * x;}

bool ispar(int u, int v) {
	return r[v] < r[u] and sqr(x[u] - x[v]) + sqr(y[u] - y[v]) < r[u] * r[u];
}

void dfs(int u) {
	LD dpsum[2] = {0., 0.};
	for (int v = 0; v < n; v++)
		if (par[v] == u) {
			h[v] = h[u]^1;
			dfs(v);
			dpsum[0] += dp[v][0];
			dpsum[1] += dp[v][1];
		}
	LD area = PI * r[u] * r[u];
	if (h[u]) {
		dp[u][0] = max(area + dpsum[1], -area + dpsum[0]);
		dp[u][1] = max(-area + dpsum[0], area + dpsum[1]);
	}
	else {
		dp[u][0] = area + max(dpsum[0], dpsum[1]);
		dp[u][1] = -area + max(dpsum[0], dpsum[1]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i] >> r[i];
	memset(par, -1, sizeof par);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (ispar(j, i) and (par[i] == -1 or r[j] < r[par[i]]))
				par[i] = j;
	LD ans = 0;
	for (int i = 0; i < n; i++)
		if (par[i] == -1) {
			dfs(i);
			ans += dp[i][0];
		}
	cout.precision(12);
	cout << fixed;
	cout << ans << endl;
	return 0;
}