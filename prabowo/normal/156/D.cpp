#include <cstdio>
#include <vector>

const int N = 100000;

int par[N];

int dsu (int x) {
	if (x == par[x]) return x;
	return par[x] = dsu(par[x]);
}

bool vis[N];
int cnt[N];

int power (long long x, int y, int mod) {
	return y ? y & 1 ? x * power (x * x % mod, y >> 1, mod) % mod : power (x * x % mod, y >> 1, mod) : 1;
}

int main () {
	int n, m, k;
	scanf ("%d %d %d", &n, &m, &k);
	
	for (int i=0; i<n; i++) par[i] = i;
	
	int u, t;
	while (m--) {
		scanf ("%d %d", &u, &t);
		u--, t--;
		
		par[dsu(u)] = dsu(t);
	}
	
	std :: vector <int> v;
	for (int i=0; i<n; i++) {
		cnt[dsu(i)]++;
		if (vis[dsu(i)]) continue;
		vis[dsu(i)] = 1;
		v.push_back (dsu(i));
	}
	
	if (v.size() == 1) return 0 * printf ("%d\n", 1 % k);
	
	long long ans = power (n, v.size() - 2, k);
	for (int i=0; i<v.size(); i++) {
		ans *= cnt[v[i]];
		ans %= k;
	}
	
	printf ("%I64d\n", ans);
	return 0;
}