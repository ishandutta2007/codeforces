#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
const int M = 30;

int n;
int a[N];

inline int getBit(int u, int x) {
	return (u >> x) & 1;
}

struct Trie {
	int cnt[N * M];
	int nxt[2][N * M];
	int tot;

	Trie() {
		tot = 1;
		memset(cnt, 0, sizeof cnt);
		memset(nxt, 0, sizeof nxt);
	}

	void add(int u) {
		int now = 1;
		for (int i = M - 1; i >= 0; i--) {
			int id = getBit(u, i);
			cnt[now]++;
			if (nxt[id][now] == 0) {
				nxt[id][now] = ++tot;
			}
			now = nxt[id][now];
		}
		cnt[now]++;
	}

	int find(int u) {
		int now = 1;
		int res = 0;
		for (int i = M - 1; i >= 0; i--) {
			int id = getBit(u, i);
			if (nxt[id][now] == 0 || cnt[nxt[id][now]] == 0) {
				id ^= 1;
				res |= (1 << i);
			} 
			now = nxt[id][now];
			cnt[now]--;
		}
		return res;
	}
} t;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++) {
		int u;
		scanf("%d", &u);
		t.add(u);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", t.find(a[i]));
	}
	printf("\n");
	return 0;
}