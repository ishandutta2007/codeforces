#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, r;
int x[N];
double y[N];

double get(int u, int v) {
	if (abs(x[u] - x[v]) > r * 2) {
		return 0;
	}
	return sqrt(4.0 * r * r - 1.0 * abs(x[u] - x[v]) * abs(x[u] - x[v])) + y[u];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> r;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	for (int i = 1; i <= n; i++) {
		double res = r;
		for (int j = 1; j < i; j++) {
			res = max(res, get(j, i));
		}
		y[i] = res;
	}
	for (int i = 1; i <= n; i++) {
		printf("%0.11f ", y[i]);
	}
	return 0;
}