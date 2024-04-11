#include <stdio.h>
#include <queue>
#include <limits.h>

#define N 100010
#define A first
#define B second
#define MP make_pair
#define INF LLONG_MAX

#define CONS 1000000
using namespace std;

typedef pair<long long, int> pii;

vector<pii> ls;

vector<pii> adj[N];
priority_queue<pii> heap;
long long dp[N];
int n, m, k;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1;i <= n;i++) {
		dp[i] = INF;
	}
	for(int i = 0;i < m;i++) {
		int u, v;
		long long x;
		scanf("%d%d%I64d", &u, &v, &x);
		adj[u].push_back(MP(x, v));
		adj[v].push_back(MP(x, u));
	}
	
	for(int i = 0;i < k;i++) {
		long long val;
		int u;
		scanf("%d%I64d", &u, &val);
		ls.push_back(MP(val, u));
	}
	
	int ans = 0;	
	heap.push(MP(0, 1));
	while(!heap.empty()) {
		long long val = -heap.top().A, u = heap.top().B;
		heap.pop();
		if(val >= dp[(u + CONS) % CONS]) {
			ans += u < 0;
			continue;
		}
		u = (u + CONS) % CONS;
		dp[u] = val;
		for(int i = 0;i < adj[u].size();i++) {
			heap.push(MP(-dp[u] - adj[u][i].A, adj[u][i].B));
		}
		if(u == 1) {
			for(int i = 0;i < ls.size();i++) {
				heap.push(MP(-dp[u] - ls[i].A, ls[i].B - CONS));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}