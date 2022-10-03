#include <cstdio>

typedef long long LL;
const int MN = 100005;

int N; LL T;
char S[MN];
int buk[26];

int main() {
	scanf("%d%lld", &N, &T);
	scanf("%s", S + 1);
	if (N == 1) return puts(T == 1 << (S[1] - 'a') ? "Yes" : "No"), 0;
	T += (1 << (S[N - 1] - 'a')) - (1 << (S[N] - 'a'));
	for (int i = 1; i <= N - 2; ++i) ++buk[S[i] - 'a'];
	for (int j = 25; j >= 0; --j) {
		while (buk[j]) {
			if (T > 0) T -= 1 << j;
			else T += 1 << j;
			--buk[j];
		}
	}
	puts(T ? "No" : "Yes");
	return 0;
}