#include <bits/stdc++.h>
using namespace std;

pair<int, int> p[105][105];
int N, M, Q, val[105][105];

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) p[i][j] = make_pair(i, j);
	while (Q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int r;
			scanf("%d", &r);
			r--;
			vector< pair<int, int> > v;
			for (int i = 0; i < M; i++) v.push_back(p[r][i]);
			for (int i = 0; i < M; i++) p[r][i] = v[(i + 1) % M];
		} else if (op == 2) {
			int c;
			scanf("%d", &c);
			c--;
			vector< pair<int, int> > v;
			for (int i = 0; i < N; i++) v.push_back(p[i][c]);
			for (int i = 0; i < N; i++) p[i][c] = v[(i + 1) % N];
		} else {
			int x, y, a;
			scanf("%d%d%d", &x, &y, &a);
			x--;
			y--;
			val[p[x][y].first][p[x][y].second] = a;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (j) printf(" ");
			printf("%d", val[i][j]);
		}
		printf("\n");
	}
}