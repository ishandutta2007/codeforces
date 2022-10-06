#include <cstdio>

const int MN = 4000005;

int Mod;
int N;
int f[MN], g[MN];

int main() {
	scanf("%d%d", &N, &Mod);
	f[N] = 1, g[N] = 1;
	for (int i = N - 1; i >= 1; --i) {
		f[i] = g[i + 1];
		for (int z = 2; i * z <= N; ++z) {
			f[i] = (f[i] + g[i * z]) % Mod;
			if (i * z + z <= N)
				f[i] = (f[i] - g[i * z + z] + Mod) % Mod;
		}
		g[i] = (g[i + 1] + f[i]) % Mod;
	}
	printf("%d\n", f[1]);
	return 0;
}