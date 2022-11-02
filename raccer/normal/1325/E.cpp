#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> ppp;

int id[1010], vis[1000010];
int prime[1010], S[1000010];
int tot;
set <int> has[1000010];
vector <pii> from[1000010];
queue <ppp> q;
int can[1000010];
vector <pii> all;

void init() {
	for (int i = 2; i <= 1000; i++) {
		if (!vis[i]) id[i] = tot, prime[tot++] = i;
		for (int j = i + i; j <= 1000; j += i) {
			vis[j] = 1;
		}
	}
}

int TOTOT = 10;

int bfs(int s) { 
	TOTOT++;
	while (!q.empty()) q.pop();
	q.push(mp(s, mp(-1, 0)));
	while (!q.empty()) {
		ppp t = q.front(); q.pop();
		int x = t.fi, edge = t.se.fi, dep = t.se.se;
		for (int i = 0; i < from[x].size(); i++) {
			int v = from[x][i].fi, id = from[x][i].se;
			if (id == edge) continue;
			if (v == s) return dep + 1;
			int pos = 2 * id + (v < S[id] - v);
			if (can[pos] == TOTOT) continue;
			can[pos] = TOTOT, q.push(mp(v, mp(id, dep + 1)));
		}
	}
	return 0x3f3f3f3f;
}

int main () {
	init();
	int n; scanf("%d", &n);
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		int p = -1, q = -1;
		for (int k = 0; k < tot; k++) {
			int j = prime[k];
			if (x % j) continue;
			int cnt = 0;
			while (x % j == 0) x /= j, cnt++;
			if (cnt & 1) {
				if (p == -1) p = j;
				else q = j;
			}
		}
		if (x != 1) {
			if (p == -1) p = x;
			else q = x;
			x = 1;
		}
		if (x == 1 && p == -1 && q == -1) {
			printf("1\n");
			return 0;
		}
		if (p != -1 && q == -1) {
			S[i] = 1 + p;
			if (has[1].count(p)) ans = 2;
			from[1].push_back(mp(p, i));
			from[p].push_back(mp(1, i));
			has[1].insert(p), has[p].insert(1);
		}
		if (p != -1 && q != -1) {
			S[i] = p + q;
			if (has[q].count(p)) ans = 2;
			from[p].push_back(mp(q, i));
			from[q].push_back(mp(p, i));
			has[q].insert(p), has[p].insert(q);
		}
	}
	if (ans == 2) {
		printf("2\n");
		return 0;
	}
	ans = min(ans, bfs(1));
	if (ans == 3) {
		printf("3\n");
		return 0;
	}
	for (int i = 0; i < tot; i++) {
		ans = min(ans, bfs(prime[i]));
		if (ans == 3) {
			printf("3\n");
			return 0;
		}
	}
	printf("%d\n", ans == 0x3f3f3f3f ? -1ll : ans);
	return 0;
}