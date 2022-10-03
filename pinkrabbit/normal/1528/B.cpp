#include <cstdio>
#include <algorithm>
#include <vector>

const int Mod = 998244353;
const int MN = 1000005;

int N;
int f[MN], s[MN];

int main() {
	scanf("%d", &N);
	f[0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = i; j <= N; j += i)
			f[j] = (f[j] + 1) % Mod;
		f[i] = (f[i] + s[i - 1]) % Mod;
		s[i] = (s[i - 1] + f[i]) % Mod;
	}
	printf("%d\n", f[N]);
	return 0;
}