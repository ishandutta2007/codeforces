#include <cstdio>
#include <cstring>
#include <vector>

inline int Abs(int x) { return x < 0 ? -x : x; }
inline int Sgn(int x) { return x < 0 ? -1 : 1; }

typedef long long LL;
const int MN = 100005, Sig = 26;
const int ML = 100005;
const int MQ = 100005;
const int T = 400; // L / sqrt(Q)
const int B = 400; // sqrt(L)

int N, Id[MN], Len[MN];
char str[ML];

int nxt[ML][Sig], faz[ML], fail[ML], Num[ML], cnt;
int que[ML], l, r;
std::vector<int> G[ML];
inline int Ins(char *S) {
	int now = 0;
	for (; *S; ++S) {
		int j = *S - 'a';
		if (!nxt[now][j])
			nxt[now][j] = ++cnt,
			faz[cnt] = now;
		now = nxt[now][j];
	}
	return now;
}
inline void BuildAC() {
	fail[0] = faz[0] = -1;
	que[l = r = 1] = 0;
	while (l <= r) {
		int u = que[l++];
		for (int j = 0; j < Sig; ++j) {
			if (nxt[u][j]) {
				fail[nxt[u][j]] = u ? nxt[fail[u]][j] : 0;
				G[fail[nxt[u][j]]].push_back(nxt[u][j]);
				que[++r] = nxt[u][j];
			}
			else nxt[u][j] = u ? nxt[fail[u]][j] : 0;
		}
	}
}
int ldf[ML], rdf[ML], dfc;
void DFS(int u) {
	ldf[u] = ++dfc;
	for (auto v : G[u]) DFS(v);
	rdf[u] = dfc;
}

int blk[ML], add[ML], tag[ML / B + 10];
inline void Add(int ql, int qr) {
	if (blk[ql] == blk[qr]) for (int i = ql; i <= qr; ++i) ++add[i];
	else {
		for (int i = ql; blk[i] == blk[ql]; ++i) ++add[i];
		for (int i = qr; blk[i] == blk[qr]; --i) ++add[i];
		for (int i = blk[ql] + 1; i < blk[qr]; ++i) ++tag[i];
	}
}
inline int Qur(int p) { return add[p] + tag[blk[p]]; }

int Q, ql[MQ], qr[MQ], qk[MQ];
LL Ans[MQ];
std::vector<std::pair<int, int>> C0[MN], C1[MN];

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; ++i) {
		scanf("%s", str);
		Len[i] = strlen(str);
		Id[i] = Ins(str);
	}
	BuildAC();
	DFS(0);
	for (int i = 1; i <= dfc; ++i) blk[i] = (i - 1) / B + 1;
	for (int i = 1; i <= Q; ++i) {
		scanf("%d%d%d", &ql[i], &qr[i], &qk[i]);
		if (ql[i] > 1) C0[ql[i] - 1].push_back({qk[i], -i});
		C0[qr[i]].push_back({qk[i], i});
	}
	for (int i = 1; i <= N; ++i) {
		Add(ldf[Id[i]], rdf[Id[i]]);
		for (auto j : C0[i]) {
			if (Len[j.first] > T) C1[j.first].push_back({i, j.second});
			else {
				int k = j.first; LL Sum = 0;
				for (int x = Id[k]; x != -1; x = faz[x]) Sum += Qur(ldf[x]);
				Ans[Abs(j.second)] += Sgn(j.second) * Sum;
			}
		}
	}
	for (int i = 1; i <= N; ++i) if (Len[i] > T) {
		for (int x = Id[i]; x != -1; x = faz[x]) ++Num[x];
		for (int j = r; j > 1; --j) Num[fail[que[j]]] += Num[que[j]];
		int p = 0; LL Sum = 0;
		for (auto x : C1[i]) {
			while (p < x.first) Sum += Num[Id[++p]];
			Ans[Abs(x.second)] += Sgn(x.second) * Sum;
		}
		for (int j = 0; j <= cnt; ++j) Num[j] = 0;
	}
	for (int i = 1; i <= Q; ++i) printf("%lld\n", Ans[i]);
	return 0;
}