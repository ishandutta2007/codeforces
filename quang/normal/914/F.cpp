#include <bits/stdc++.h>

using namespace std;

const int N = 100010, MAGIC = 320;

int n, q;
char a[N], s[N];
int t[N];
int boundL[N / MAGIC + 10], boundR[N / MAGIC + 10];
int numBlock;

struct SuffixAutomaton {
	int link[26][MAGIC << 1], suffixLink[MAGIC << 1], len[MAGIC << 1];
	int cnt[MAGIC << 1], last, now;
	int dp[MAGIC << 1];
	vector<int> a[MAGIC << 1];

	void init() {
		now = last = 0;
		memset(link, -1, sizeof link);
		memset(suffixLink, -1, sizeof suffixLink);
		for (int i = 0; i < MAGIC * 2; i++) {
			a[i].clear();
		}
	}

	int getNode(int last, int u) {
		int q = link[u][last];
		if (len[q] == len[last] + 1) {
			return q;
		}
		int clone = ++now;
		len[clone] = len[last] + 1;
		cnt[clone] = 0;
		for (int i = 0; i < 26; i++) {
			link[i][clone] = link[i][q];
		}
		while (last != -1 && link[u][last] == q) {
			link[u][last] = clone;
			last = suffixLink[last];
		}
		suffixLink[clone] = suffixLink[q];
		return suffixLink[q] = clone;
	}

	void add(char u) {
		u -= 'a';
		if (link[u][last] == -1) {
			int newNode = ++now;
			cnt[newNode] = 1;
			len[newNode] = len[last] + 1;
			while (last != -1 && link[u][last] == -1) {
				link[u][last] = newNode;
				last = suffixLink[last];
			}
			if (last == -1) {
				suffixLink[newNode] = 0;
				last = newNode;
				return;
			}
			suffixLink[newNode] = getNode(last, u);
			last = newNode;
		} else {
			last = getNode(last, u);
		}
	}

	void dfs(int u) {
		dp[u] = cnt[u];
		for (int v : a[u]) {
			dfs(v);
			dp[u] += dp[v];
		}
	}

	void build() {	
		for (int i = 1; i <= now; i++) {
			a[suffixLink[i]].push_back(i);
		}
		dfs(0);
	}

	int getNum(char *s, int sz) {
		int curNode = 0;
		for (int i = 1; i <= sz; i++) {
			curNode = link[s[i] - 'a'][curNode];
			if (curNode == -1) {
				return 0;
			}
		}
		return dp[curNode];
	}
} sa[N / MAGIC + 10];

void updateSA(int u) {
	sa[u].init();
	for (int i = boundL[u]; i <= boundR[u]; i++) {
		sa[u].add(a[i]);
	}
	sa[u].build();
}

void init() {
	int numBlock = (n - 1) / MAGIC + 1;
	for (int i = 1; i <= numBlock; i++) {
		boundL[i] = (i - 1) * MAGIC + 1;
		boundR[i] = min(n, i * MAGIC);
		updateSA(i);
	}
}

void update(int id, char u) {
	int block = (id - 1) / MAGIC + 1;
	a[id] = u;
	updateSA(block);
}

int findRes(int l, int r, int sz) {	
	int res = 0;
	int cur = 0;
	for (int i = l; i <= r; i++) {
		while (cur && s[cur + 1] != a[i]) {
			cur = t[cur];
		}
		cur += (s[cur + 1] == a[i]);		
		res += cur == sz;
	}
	return res;
}

int main() {
	scanf("%s", a + 1);
	scanf("%d", &q);
	n = strlen(a + 1);
	init();
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int id;
			char u;
			scanf("%d %c", &id, &u);
			update(id, u);
		} else {
			int l, r;
			scanf("%d %d %s", &l, &r, s + 1);
			int sz = strlen(s + 1);
			int cur = 0;
			for (int i = 2; i <= sz; i++) {
				while (cur && s[cur + 1] != s[i]) {
					cur = t[cur];
				}
				cur += (s[cur + 1] == s[i]);
				t[i] = cur;
			}
			int res = 0;	
			if (sz >= MAGIC) {
				res += findRes(l, r, sz);
			} else {	
				int lBlock = (l - 1) / MAGIC + 1;
				int rBlock = (r - 1) / MAGIC + 1;	
				if (lBlock == rBlock) {
					res += findRes(l, r, sz);
				} else {
					res += findRes(l, boundR[lBlock], sz);
					res += findRes(boundL[rBlock], r, sz);
					for (int i = lBlock + 1; i < rBlock; i++) {
						res += sa[i].getNum(s, sz);
					}
					for (int i = lBlock; i < rBlock; i++) {
						int ll = max(l, boundL[i + 1] - sz + 1);
						int rr = min(r, boundR[i] + sz - 1);
						res += findRes(ll, rr, sz);
					}
				}
			}
			printf("%d\n", res);
		}
	}
	return 0;
}