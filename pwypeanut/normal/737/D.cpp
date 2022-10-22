#include <bits/stdc++.h>
using namespace std;

vector<int> v[4005][4005][2];
int N;
long long a[4005];

int sum(int x, int y) {
	return a[y] - ((x == 0) ? 0 : a[x - 1]);
}

int f(int x, int y, int turn, int k) {
	// extend either k + 1 or k + 2
	if (N - x - y < k + 1) return 0;
	if (v[x][y][turn].size() < k + 1) {
		while (v[x][y][turn].size() < k + 1) v[x][y][turn].push_back(-2100000000);
	}
	if (v[x][y][turn][k] != -2100000000) return v[x][y][turn][k];
	if (turn == 0) {
		// attempt k + 1
		int maxi = -2000000000;
		int val = sum(x, x + k);
		maxi = max(maxi, f(x + (k + 1), y, !turn, k) + val);
		// attempt k + 2
		if (N - x - y >= k + 2) {
			val = sum(x, x + (k + 1));
			maxi = max(maxi, f(x + (k + 2), y, !turn, k + 1) + val);
		}
		//printf("%d %d %d %d = %d\n", x, y, turn, k, maxi);
		return v[x][y][turn][k] = maxi;
	} else {
		int mini = 2000000000;
		int val = sum(N - y - 1 - k, N - y - 1);
		mini = min(mini, f(x, y + (k + 1), !turn, k) - val);
		if (N - x - y >= k + 2) {
			val = sum(N - y - 2 - k, N - y - 1);
			mini = min(mini, f(x, y + (k + 2), !turn, k + 1) - val);
		}
		//printf("%d %d %d %d = %d\n", x, y, turn, k, mini);
		return v[x][y][turn][k] = mini;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	for (int i = 1; i < N; i++) a[i] += a[i - 1];
	printf("%d\n", f(0, 0, 0, 0));
}