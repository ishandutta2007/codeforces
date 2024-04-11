#include <bits/stdc++.h>
using namespace std;

#define MN 1000005

int N, M;
int b[MN], f[MN][3][3];

int main(){
	scanf("%d%d", &N, &M);
	for (int i = 1, x; i <= N; ++i) scanf("%d", &x), ++b[x];
	for (int i = 1; i <= M; ++i)
		for (int j = 0; j < 3 ; ++j)
			for (int k = 0; k < 3 ; ++k)
				for (int l = 0; l < 3 ; ++l)
					if (b[i] < j + k + l) continue ;
					else f[i][k][l] = max(f[i][k][l], f[i - 1][j][k] + (b[i] - j - k - l) / 3 + l);
	printf("%d\n", f[M][0][0]);
	return 0;
}