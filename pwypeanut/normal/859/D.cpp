#include <bits/stdc++.h>
using namespace std;

int N, arr[66][66];
bool vis[66][66][66], vis2[66][66][66];
double exp1[66][66][66], p1[66][66][66];

double p(int s, int e, int w) {
	if (vis2[s][e][w]) return p1[s][e][w];
	if (e == s + 1) return 1;
	int m = (s + e) / 2;
	double ans = 0;
	if (w < m) {
		for (int j = m; j < e; j++) {
			ans += p(s, m, w) * p(m, e, j) * (double)arr[w][j] / 100;
		}
	} else {
		for (int i = s; i < m; i++) {
			ans += p(s, m, i) * p(m, e, w) * (double)arr[w][i] / 100;
		}
	}
	vis2[s][e][w] = 1;
	p1[s][e][w] = ans;
	//printf("%d %d %d %Lf\n", s, e, w, ans);
	return ans;
}

double f(int s, int e, int w) {
	if (vis[s][e][w]) return exp1[s][e][w];
	if (e == s + 1) return 0;
	int m = (s + e) / 2;
	double ans = 0;
	if (w < m) {
		for (int j = m; j < e; j++) {
			ans = max(ans, (f(s, m, w) + f(m, e, j)) + (double)(e - s) / 2 * p(s, e, w));
		}
	} else {
		for (int i = s; i < m; i++) {
			ans = max(ans, (f(s, m, i) + f(m, e, w)) + (double)(e - s) / 2 * p(s, e, w));
		}
	}
	exp1[s][e][w] = ans;
	vis[s][e][w] = 1;
	//printf("%d %d %d = %Lf\n", s, e, w, ans);
	return ans;
}

int main() {
	scanf("%d", &N);
	N = (1 << N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	double mx = 0;
	for (int i = 0; i < N; i++) mx = max(mx, f(0, N, i));
	printf("%.12lf\n", mx);
}