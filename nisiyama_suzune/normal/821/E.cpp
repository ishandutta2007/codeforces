#include <bits/stdc++.h>

#ifdef WIN32
	#define LL "%I64d"
#else
	#define LL "%lld"
#endif

const long long MOD = 1E9 + 7;

long long N, K;
long long ans[20][20], mat[20][20], mul[20][20];

int main () {
	scanf (LL LL, &N, &K);
	for (int i = 0; i < 20; ++i)
		ans[i][i] = 1;
	for (int i = 0; i < N; ++i) {
		long long l, r, c;
		scanf (LL LL LL, &l, &r, &c);
		for (int j = 0; j < 20; ++j)
			for (int k = 0; k < 20; ++k)
				mat[j][k] = 0;
		for (int j = 0; j <= c; ++j)
			for (int off = -1; off <= 1; ++off)
				if (j + off >= 0 && j + off <= c) {
					mat[j][j + off] = 1;
				}
		if (r > K) r = K;
		long long M = r - l;
		while (M) {
			if (M & 1) {
				for (int i = 0; i < 20; ++i)
					for (int j = 0; j < 20; ++j)
						mul[i][j] = 0;
				for (int i = 0; i < 20; ++i)
					for (int j = 0; j < 20; ++j)
						for (int k = 0; k < 20; ++k)
							mul[i][j] = (mul[i][j] + ans[i][k] * mat[k][j] % MOD) % MOD;
				for (int i = 0; i < 20; ++i)
					for (int j = 0; j < 20; ++j)
						ans[i][j] = mul[i][j];
			}
			for (int i = 0; i < 20; ++i)
				for (int j = 0; j < 20; ++j)
					mul[i][j] = 0;
			for (int i = 0; i < 20; ++i)
				for (int j = 0; j < 20; ++j)
					for (int k = 0; k < 20; ++k)
						mul[i][j] = (mul[i][j] + mat[i][k] * mat[k][j] % MOD) % MOD;
			for (int i = 0; i < 20; ++i)
				for (int j = 0; j < 20; ++j)
					mat[i][j] = mul[i][j];
			M >>= 1;
		}
	}
	printf (LL "\n", ans[0][0] % MOD);
}