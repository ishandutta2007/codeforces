#include <cstdio>
#include <algorithm>
#include <set>

const int Inf = 0x3f3f3f3f;
const int MN = 100005;

int N, M, K, A[MN], C[MN];
int S[MN], H[MN];
int len[MN], pos[MN];
int f[MN], g[MN];
std::multiset<int> st;
int Ans[MN];

int main() {
	scanf("%d", &N), N += 2, A[1] = 0, A[N] = 1000000001;
	for (int i = 2; i < N; ++i) scanf("%d", &A[i]);
	for (int i = 1; i <= N; ++i) {
		S[i] = S[i - 1];
		if (A[i] == -1) ++S[i], H[S[i]] = i;
	}
	scanf("%d", &M);
	for (int i = 1; i <= M; ++i) scanf("%d", &C[i]), st.insert(C[i]);
	std::sort(C + 1, C + M + 1), K = std::unique(C + 1, C + M + 1) - C - 1;
	for (int i = 1; i <= N; ++i) f[i] = Inf, g[i] = 0;
	for (int i = 1; i <= N; ++i) {
		if (A[i] == -1) {
			int k = N;
			for (int j = K; j >= 1; --j) {
				while (k > 1 && f[k - 1] >= C[j]) --k;
				f[k] = C[j];
				g[k] = -1;
			}
		} else {
			int p = std::lower_bound(f + 1, f + N + 1, A[i]) - f;
			len[i] = p;
			pos[i] = p > 1 ? g[p - 1] : 0;
			f[p] = A[i];
			g[p] = i;
		}
	}
	for (int i = 1; i <= N; ++i) Ans[i] = -1;
	int lst = N; Ans[N] = A[N];
	for (int i = N - 1; i >= 1; --i) if (A[i] != -1) {
		Ans[i] = A[i];
		if (A[i] < A[lst]) {
			int upos = std::lower_bound(C + 1, C + K + 1, A[lst]) - C;
			int num = upos - (std::upper_bound(C + 1, C + K + 1, A[i]) - C);
			num = std::min(num, S[lst] - S[i]);
			if (len[lst] - len[i] == num + 1) {
				for (int j = 1; j <= num; ++j) {
					Ans[H[S[lst] - j + 1]] = C[upos - j];
					st.erase(st.find(C[upos - j]));
				}
				lst = i;
			}
		}
	}
	for (int i = 1; i <= N; ++i) if (Ans[i] == -1) Ans[i] = *st.begin(), st.erase(st.begin());
	for (int i = 2; i < N; ++i) printf("%d%c", Ans[i], " \n"[i == N - 1]);
	return 0;
}