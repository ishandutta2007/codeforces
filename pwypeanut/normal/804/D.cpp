#include <bits/stdc++.h>
using namespace std;

int N, M, Q, cc[100005], cur, d1[100005], d2[100005], dia[100005], far[100005];
vector<int> roots, ccs[100005], vals[100005];
vector<long long> cumsum[100005];
bool vis[100005];
vector<int> v[100005];
map< pair<int, int>, double > memo;

void dfs(int x, int p) {
	if (vis[x]) return;
	else vis[x] = 1;
	cc[x] = cur;
	ccs[cur].push_back(x);
	for (int i = 0; i < v[x].size(); i++) if (v[x][i] != p) dfs(v[x][i], x);
}

void dfs2(int x, int p, int d) {
	d1[x] = d;
	for (int i = 0; i < v[x].size(); i++) if (v[x][i] != p) dfs2(v[x][i], x, d + 1);
}
void dfs3(int x, int p, int d) {
	d2[x] = d;
	for (int i = 0; i < v[x].size(); i++) if (v[x][i] != p) dfs3(v[x][i], x, d + 1);
}

int main() {	
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		if (vis[i]) continue;
		dfs(i, -1);
		cur++;
		roots.push_back(i);
	}
	for (int i = 0; i < roots.size(); i++) {
		dfs2(roots[i], -1, 0);
		int mxd = -1, best = 0;
		for (int j = 0; j < ccs[i].size(); j++) {
			int node = ccs[i][j];
			if (d1[node] > mxd) {
				mxd = d1[node];
				best = node;
			}
		}
		dfs2(best, -1, 0);
		mxd = -1;
		best = 0;
		for (int j = 0; j < ccs[i].size(); j++) {
			int node = ccs[i][j];
			if (d1[node] > mxd) {
				mxd = d1[node];
				best = node;
			}
		}
		dia[i] = mxd;
		dfs3(best, -1, 0);
	}
	for (int i = 0; i < N; i++) far[i] = max(d1[i], d2[i]);
	for (int i = 0; i < roots.size(); i++) for (int j = 0; j < ccs[i].size(); j++) vals[i].push_back(far[ccs[i][j]]);
	for (int i = 0; i < roots.size(); i++) sort(vals[i].begin(), vals[i].end());
	for (int i = 0; i < roots.size(); i++) {
		long long c = 0;
		for (int j = vals[i].size() - 1; j >= 0; j--) {
			c += vals[i][j];
			cumsum[i].push_back(c);
		}
		reverse(cumsum[i].begin(), cumsum[i].end());
	}
	while (Q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		if (cc[a] == cc[b]) {
			printf("-1\n");
			continue;
		}
		a = cc[a];
		b = cc[b];
		if (memo.find(make_pair(min(a, b), max(a, b))) != memo.end()) {
			printf("%.8lf\n", memo[make_pair(min(a, b), max(a, b))]);
			continue;
		}
		if (ccs[a].size() > ccs[b].size()) swap(a, b);
		int mxd = max(dia[a], dia[b]);
		double sum = 0;
		for (int i = 0; i < ccs[a].size(); i++) {
			int lval = vals[a][i];
			int thres = mxd - lval - 1;
			int pos = lower_bound(vals[b].begin(), vals[b].end(), thres) - vals[b].begin();
			long long tval = ((pos == ccs[b].size()) ? 0ll : cumsum[b][pos]) + (long long)pos * thres;
			double ex = (double)tval / ccs[b].size() + lval + 1;
			sum += ex;
		}
		sum /= ccs[a].size();
		memo[make_pair(min(a, b), max(a, b))] = sum;
		printf("%.8lf\n", sum);
	}
}