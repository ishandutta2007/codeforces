#include <bits/stdc++.h>
using namespace std;

int N, R, F[55], S[55], P[55];
double exp1[55][6005];

int main() {
	scanf("%d%d", &N, &R);
	for (int i = 0; i < N; i++) scanf("%d%d%d", &F[i], &S[i], &P[i]);
	double bot = 0, top = 1000000000, mid;
	while (bot + 1e-10 < top) {
		mid = (bot + top) / 2;
		for (int i = R+1; i <= 6000; i++) exp1[N][i] = mid;
		for (int i = 0; i <= R; i++) exp1[N][i] = 0;
		for (int i = N-1; i >= 0; i--) {
			for (int j = 0; j <= 5000; j++) {
				int t1 = j + F[i], t2 = j + S[i];
				exp1[i][j] = (((double)P[i] / 100) * (exp1[i+1][t1] + F[i])) + (((double)(100 - P[i]) / 100) * (exp1[i+1][t2] + S[i]));
				if (!(i==0&&j==0))exp1[i][j] = min(mid, exp1[i][j]);
			}
		}
		//printf("%lf: %lf\n", mid, exp1[0][0]);
		if (exp1[0][0] < mid) top = mid;
		else bot = mid;
	}
	printf("%.10lf\n", bot);
}