#include <bits/stdc++.h>
using namespace std;

int N, M, G[105][105], mn = 1000000000;

vector<int> xs, ys;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf("%d", &G[i][j]);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) mn = min(mn, G[i][j]);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) G[i][j] -= mn;
	int x = 0, y = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (G[i][j] == 0) {
				x = i;
				y = j;
			}
		}
	}
	if (N < M) {
		for (int i = 0; i < N; i++) for (int j = 0; j < mn; j++) xs.push_back(i);
	} else {
		for (int i = 0; i < M; i++) for (int j = 0; j < mn; j++) ys.push_back(i);
	}
	for (int i = 0; i < M; i++) {
		int val = G[x][i];
		for (int j = 0; j < val; j++) {
			ys.push_back(i);
			for (int k = 0; k < N; k++) G[k][i]--;
		}
	}
	for (int i = 0; i < N; i++) {
		int val = G[i][0];
		for (int j = 0; j < val; j++) {
			xs.push_back(i);
			for (int k = 0; k < M; k++) G[i][k]--;
		}
	}
	bool fail = 0;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (G[i][j] != 0) fail = 1;
	if (fail) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", xs.size() + ys.size());
	for (int i = 0; i < xs.size(); i++) {
		printf("row %d\n", xs[i] + 1);
	}
	for (int i =0; i < ys.size(); i++) printf("col %d\n", ys[i] + 1);
}