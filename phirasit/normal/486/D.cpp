#include <stdio.h>
#include <algorithm>
#include <vector>

#define N 2010
#define PB push_back
#define MOD 1000000007

using namespace std;

vector<int> adj[N];

int in[N];

int arr[N];
int idx[N];
int n, d;

int val;

int cmp(int a, int b) {
	return arr[a] < arr[b];
}
long long dfs(int u, int p) {
	long long cnt = 1;
	for(int i = 0;i < adj[u].size();i++) {
		int v = adj[u][i];
		if(v == p || !in[v] || val - arr[v] > d) {
			continue;
		}
		cnt *= (long long) dfs(v, u);
		cnt %= MOD;
	}
	return cnt + 1;
}
int main() {
	scanf("%d%d", &d, &n);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &arr[i]);
		idx[i] = i;
		in[i] = 0;
	}
	sort(idx+1, idx+n+1, cmp);
	for(int i = 0;i < n-1;i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	long long ans = 0;
	for(int i = 1;i <= n;i++) {
		int u = idx[i];
		in[u] = 1;
		val = arr[u];
		ans += dfs(u, -1) - 1;
		ans %= MOD;
	}
	printf("%I64d\n", (ans + MOD) % MOD);
	return 0;
}