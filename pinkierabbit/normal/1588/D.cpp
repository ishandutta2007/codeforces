#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

const int MN = 10;

inline int t(char c) { return 'a' <= c && c <= 'z' ? c - 'a' : c - 'A' + 26; }

int N, len[MN];
char str[MN][155];
int val[MN][155], nxt[MN][155][52], pos[MN][52][2];
int dis[52 << MN], tr[52 << MN], inq[52 << MN];

void Solve() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s", str[i] + 1);
		len[i] = (int)std::strlen(str[i] + 1);
		static int p[52];
		for (int j = 0; j < 52; ++j)
			p[j] = 0;
		for (int k = len[i]; k >= 1; --k) {
			for (int j = 0; j < 52; ++j)
				nxt[i][k][j] = p[j];
			val[i][k] = 1;
			p[t(str[i][k])] = k;
		}
		for (int j = 0; j < 52; ++j) {
			nxt[i][0][j] = p[j];
			if (p[j])
				val[i][p[j]] = 0;
		}
		for (int k = 1; k <= len[i]; ++k)
			pos[i][t(str[i][k])][val[i][k]] = k;
//		for (int k = 1; k <= len[i]; ++k)
//			printf("%d", val[i][k]);
//		puts("");
	}
	std::memset(dis, 0, sizeof dis);
	std::memset(tr, 0, sizeof tr);
	std::memset(inq, 0, sizeof inq);
	std::priority_queue<std::pair<int, int>> pq;
	for (int j = 0; j < 52; ++j) {
		int ok = 1, st = j << N, pr = 0;
		for (int i = 0; i < N; ++i) {
			int p = nxt[i][0][j];
			if (p)
				st |= val[i][p] << i,
				pr += p;
			else
				ok = 0;
		}
		if (ok)
			dis[st] = 1, tr[st] = -1,
			!inq[st] ? inq[st] = 1, pq.push({-pr, st}) : void();
	}
	int mxv = 0, mxs = 0;
	while (!pq.empty()) {
		auto pii = pq.top(); pq.pop();
		int stn = pii.second;
		int d = dis[stn];
		int c = stn >> N;
		int s = stn & ((1 << N) - 1);
		if (d > mxv)
			mxv = d,
			mxs = stn;
//		printf("dis[%c | ", c < 26 ? 'a' + c : 'A' + (c - 26));
//		for (int x = 0; x < N; ++x)
//			printf("%d", s >> x & 1);
//		printf("] = %d\n", d);
		for (int j = 0; j < 52; ++j) {
			int ok = 1, st = j << N, pr = 0;
			for (int i = 0; i < N; ++i) {
				int p = nxt[i][pos[i][c][s >> i & 1]][j];
				if (p)
					st |= val[i][p] << i,
					pr += p;
				else
					ok = 0;
			}
			if (ok && d >= dis[st])
				dis[st] = d + 1, tr[st] = stn,
				!inq[st] ? inq[st] = 1, pq.push({-pr, st}) : void();
		}
	}
	if (!mxv) {
		printf("0\n\n");
		return ;
	}
	static char out[155];
	int tp = 0;
	while (mxs != -1) {
		int c = mxs >> N;
		out[++tp] = c < 26 ? 'a' + c : 'A' + (c - 26);
		mxs = tr[mxs];
	}
	printf("%d\n", mxv);
	while (tp) printf("%c", out[tp--]);
	puts("");
}

int main() {
	int Tests;
	scanf("%d", &Tests);
	while (Tests--)
		Solve();
	return 0;
}