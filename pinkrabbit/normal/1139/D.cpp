#include <cstdio>
#include <vector>

typedef long long LL;
const int Mod = 1e9 + 7;
const int MM = 100005;

int M;
int ip[MM], p[MM], mu[MM], pc, inv[MM];
std::vector<int> D[MM], C[MM];
int f[MM], Ans;

int main() {
	scanf("%d", &M);
	mu[1] = inv[1] = 1;
	for (int i = 2; i <= M; ++i) {
		inv[i] = (LL)(Mod - Mod / i) * inv[Mod % i] % Mod;
		if (!ip[i]) p[++pc] = i, mu[i] = -1;
		for (int j = 1; j <= pc; ++j) {
			if (p[j] * i > M) break;
			ip[p[j] * i] = 1;
			if (i % p[j]) mu[p[j] * i] = -mu[i];
			else break;
		}
	}
	for (int i = 1; i <= M; ++i) {
		for (int j = i; j <= M; j += i) {
			for (int k = 0; k < (int)D[j].size(); ++k)
				if (i % D[j][k] == 0) C[j][k] += M / i * mu[i / D[j][k]];
			D[j].push_back(i);
			C[j].push_back(M / i);
		}
	}
/*	for (int i = 1; i <= M; ++i)
		for (int j = 0; j < (int)D[i].size(); ++j)
			printf("%d <- %d, %d\n", i, D[i][j], C[i][j]);*/
	f[1] = 0;
	for (int i = 2; i <= M; ++i) {
		f[i] = M;
		for (int j = 0; j < (int)D[i].size() - 1; ++j)
			f[i] = (f[i] + (LL)C[i][j] * f[D[i][j]]) % Mod;
		f[i] = (LL)f[i] * inv[M - C[i][(int)D[i].size() - 1]] % Mod;
	}
	Ans = M;
	for (int i = 1; i <= M; ++i) Ans = (Ans + f[i]) % Mod;
	Ans = (LL)Ans * inv[M] % Mod;
	printf("%d\n", Ans);
	return 0;
}

// lg