#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

vector< pair< int, pair<int, int> > > edges;
vector<int> groups[1505];
int cnt[1505], p[1505], sze[1505], groupedges[1505];
int nodetop[1505], dp[3505][1505];
vector<int> children[3505];
int nodes;

int fp(int x) {
	if (p[x] == x) return x;
	else return p[x] = fp(p[x]);
}

void merge(int x, int y) {
	x = fp(x);
	y = fp(y);
	if (x == y) {
		return;
	}
	if (sze[x] > sze[y]) swap(x, y);
	p[x] = y;
	sze[y] += sze[x];
	groupedges[y] += groupedges[x];
	for (int i = 0; i < groups[x].size(); i++) groups[y].push_back(groups[x][i]);
}

int N, sze1[3505];

int getsze(int x, int p) {
	int sum = 1;
	for (int i = 0; i < children[x].size(); i++) sum += getsze(children[x][i], x);
	return sze1[x] = sum;
}

int f(int n, int k) {
	if (dp[n][k] != -1) return dp[n][k];
	if (k == 1) return 1;
	if (k > sze1[n]) return 0;
	if (k < 1 || (k > 1 && k < children[n].size())) return 0;
	//printf("got %d %d\n", n, k);
	int dp2[children[n].size() + 1][N + 1];
	for (int i = 0; i <= N; i++) dp2[0][i] = 0;
	dp2[0][0] = 1;
	for (int i = 1; i <= children[n].size(); i++) {
		dp2[i][0] = 0;
		for (int j = 1; j <= N; j++) {
			dp2[i][j] = 0;
			dp2[i][j] += ((long long)dp2[i - 1][j - 1] * f(children[n][i - 1], 1)) % MOD;
			dp2[i][j] %= MOD;
			for (int m = max(2, (int)children[children[n][i - 1]].size()); m <= min(j, sze1[children[n][i - 1]]); m++) {
				dp2[i][j] += ((long long)dp2[i - 1][j - m] * f(children[n][i - 1], m)) % MOD;
				dp2[i][j] %= MOD;
			}
		}
	}
	dp[n][0] = 0;
	dp[n][1] = 0;
	for (int i = 2; i <= N; i++) {
		dp[n][i] = dp2[children[n].size()][i];
		//printf("%d %d = %d\n", n, i, dp[n][i]);
	}
	dp[n][1] += 1;
	return dp[n][k];
}

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		p[i] = i;
		sze[i] = 1;
		groups[i].push_back(i);
		nodetop[i] = i;
	}
	nodes = N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x;
			scanf("%d", &x);
			if (i < j) edges.push_back(make_pair(x, make_pair(i, j)));
		}
	}
	sort(edges.begin(), edges.end());
	cnt[N]++;
	for (int i = 0; i < edges.size(); i++) {
		merge(edges[i].second.first, edges[i].second.second);
		groupedges[fp(edges[i].second.first)]++;
		if (groupedges[fp(edges[i].second.first)] == sze[fp(edges[i].second.first)] * (sze[fp(edges[i].second.first)] - 1) / 2) {
			vector<int> v;
			//printf("clique %d found:", nodes);
			for (int j = 0; j < groups[fp(edges[i].second.first)].size(); j++) {
				
				v.push_back(nodetop[groups[fp(edges[i].second.first)][j]]);
				nodetop[groups[fp(edges[i].second.first)][j]] = nodes;
				//printf(" %d", groups[fp(edges[i].second.first)][j]);
			}
			//printf("\n");
			sort(v.begin(), v.end());
			v.resize(unique(v.begin(), v.end()) - v.begin());
			//for (int j = 0; j < v.size(); j++) printf("%d\n", v[j]);
			children[nodes] = v;
			nodes++;
		}
	}
	//printf("total nodes: %d\n", nodes);
	for (int i = 0; i < nodes; i++) {
		//printf("%d:", i);
		//for (int j = 0; j < children[i].size(); j++) printf(" %d", children[i][j]);
		//printf("\n");
	}
	getsze(nodes - 1, -1);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= N; i++) {
		if (i != 1) printf(" ");
		printf("%d", f(nodes - 1, i));
	}
	printf("\n");
}