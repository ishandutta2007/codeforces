#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n , f[N]; double p[N][N] , s[N] , E[N];

int main() {
	scanf("%d" , &n);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		scanf("%lf" , &p[i][j]) , p[i][j] /= 100.0;
	for (int i = 1; i < n; i++) E[i] = 1 , s[i] = 1.0 - p[i][n];
	f[n] = 1;
	for (int t = 1; t < n; t++) {
		double Min = 1e18; int j = 0;
		for (int i = 1; i <= n; i++) if(!f[i] && E[i] / (1.0 - s[i]) < Min)
			Min = E[i] / (1.0 - s[i]) , j = i;
		f[j] = 1;
		for (int i = 1; i <= n; i++) if(!f[i])
			E[i] += E[j] / (1.0 - s[j]) * p[i][j] * s[i] , s[i] *= 1.0 - p[i][j];
	}
	printf("%.10f\n" , E[1] / (1.0 - s[1]));
	return 0;
}