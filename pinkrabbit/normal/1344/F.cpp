#include <cstdio>
#include <algorithm>
#include <bitset>
#include <map>

const int MN = 1005, MQ = 1005;
const std::map<char, int> t = {{'W', 0}, {'R', 1}, {'B', 2}, {'Y', 3}};

int N, Q, S[2][MN], Ans[MN], C;
std::bitset<MN * 2> W[MQ * 2];

void Init() {
	char s[5];
	int c, a[MN];
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; ++i) S[0][i] = 1, S[1][i] = 2;
	for (int i = 1; i <= Q; ++i) {
		scanf("%s%d", s, &c);
		for (int j = 1; j <= c; ++j) scanf("%d", &a[j]);
		if (*s == 'm') {
			scanf("%s", s);
			int x = t.at(*s);
			for (int o = 0; o < 2; ++o) {
				++C;
				for (int j = 1; j <= c; ++j) {
					int y = S[o][a[j]];
					if (y & 1) W[C].set(2 * a[j] - 1);
					if (y & 2) W[C].set(2 * a[j]);
				}
				if (x >> o & 1) W[C].set(2 * N + 1);
			}
		} else if (*s == 'Y') {
			for (int j = 1; j <= c; ++j)
				S[0][a[j]] ^= S[1][a[j]];
		} else if (s[1] == 'Y') {
			for (int j = 1; j <= c; ++j)
				S[1][a[j]] ^= S[0][a[j]];
		} else {
			for (int j = 1; j <= c; ++j)
				std::swap(S[1][a[j]], S[0][a[j]]);
		}
	}
}

int Gauss() {
	int l = 1;
	for (int i = 1; i <= 2 * N + 1; ++i) {
		int o = 0;
		for (int j = l; j <= C; ++j) if (W[j][i]) { o = j; break; }
		if (!o) continue;
		if (o != l) std::swap(W[l], W[o]);
		for (int j = 1; j <= C; ++j) if (j != l && W[j][i])
			W[j] ^= W[l];
		++l;
	}
	return l - 1;
}

int main() {
	Init();
	int l = Gauss();
	if ((int)W[l]._Find_first() == 2 * N + 1) return puts("NO"), 0;
	puts("YES");
	for (int i = 1; i <= l; ++i) if (W[i][2 * N + 1]) {
		int x = W[i]._Find_first();
		if (x & 1) Ans[x / 2 + 1] |= 1;
		else Ans[x / 2] |= 2;
	}
	for (int i = 1; i <= N; ++i) putchar(".RBY"[Ans[i]]);
	puts("");
	return 0;
}