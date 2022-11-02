#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int f1[2010], f2[2010];
int n, m1, m2;
int to1[2010], to2[2010];
int in1[2010], in2[2010];
int ll[2010], rr[2010], size[2010];
queue <int> q;
vector <pii> from[2010];

void solve(int n, int *to, int *fa, int *in) {
	for (int i = 1; i <= n; i++) {
		ll[i] = 0x3f3f3f3f, rr[i] = -0x3f3f3f3f, size[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			q.push(i);
			if (to[i]) ll[i] = rr[i] = to[i];
		}
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (ll[x] <= rr[x]) from[ll[x]].push_back(mp(rr[x], size[x] - (x == 1)));
		int p = fa[x];
		size[p] += size[x], ll[p] = min(ll[p], ll[x]), rr[p] = max(rr[p], rr[x]), in[p]--;
		if (!in[p]) q.push(p);
	}
}

int dp[2010];

int main () {
	scanf("%d", &n);
	scanf("%d", &m1);
	for (int i = 2; i <= m1; i++) {
		scanf("%d", &f1[i]), in1[f1[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		to1[x] = i;
	}
	scanf("%d", &m2);
	for (int i = 2; i <= m2; i++) {
		scanf("%d", &f2[i]), in2[f2[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		to2[x] = i;
	}
	solve(m1, to1, f1, in1), solve(m2, to2, f2, in2);
	for (int i = 1; i <= n; i++) {
		dp[i] = -0x3f3f3f3f;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < from[i].size(); j++) {
			int r = from[i][j].fi, s = from[i][j].se;
			if (r < i) continue;
			dp[r] = max(dp[r], dp[i - 1] + s);
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}