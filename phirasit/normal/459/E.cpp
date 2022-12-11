#include <stdio.h>
#include <vector>
#include <algorithm>

#define A first
#define B second

#define N 300010

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> pi3;

pi3 edge[N];
int dp[N];
int n, m;

int cmp(pi3 a, pi3 b) {
	return a.B > b.B;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++) {
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edge[i] = make_pair(make_pair(a, b), w);
	}
	for(int i = 0;i <= n;i++) {
		dp[i] = 0;
	}
	sort(edge, edge+m, cmp);
	int ans = 0;
	for(int i = 0;i < m;) {
		vector<pii> V;
		V.clear();
		int j = i;
		while(j < m && edge[i].B == edge[j].B) {
			int u = edge[j].A.A, v = edge[j].A.B;
			V.push_back(make_pair(u, dp[v]+1));
			j++;
		}
		for(int k = 0;k < V.size();k++) {
			dp[V[k].A] = max(dp[V[k].A], V[k].B);
			ans = max(ans, dp[V[k].A]);
		}
		printf("\n");
		i = j;
	}
	printf("%d\n", ans);
	return 0;
}