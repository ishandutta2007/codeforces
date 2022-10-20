#include <bits/stdc++.h>

using namespace std;

const int N = 60;
const int dirX[] = {0, 1, 0, -1};
const int dirY[] = {1, 0, -1, 0};

int n, m, sz;
char a[N][N], s[N * N];
int b[4];
pair<int, int> start, finish;

bool checkPoint(int u, int v) {
	if (u < 1 || u > n) return 0;
	if (v < 1 || v > m) return 0;
	return a[u][v] != '#';
}

int check() {
	int u = start.first;
	int v = start.second;
	for (int i = 1; i <= sz; i++) {
		int dir = b[s[i] - '0'] - 1;
		int uu = u + dirX[dir];
		int vv = v + dirY[dir];
		if (!checkPoint(uu, vv)) {
			return 0;
		}
		u = uu;
		v = vv;
		if (u == finish.first && v == finish.second) {
			return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", a[i] + 1);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 'S') {
				start = make_pair(i, j);
			}
			if (a[i][j] == 'E') {
				finish = make_pair(i, j);
			}
		}
	}
	scanf("%s", s + 1);
	sz = strlen(s + 1);
	for (int i = 0; i < 4; i++) b[i] = i + 1;
	int res = 0;
	while (1) {
		res += check();
		if (!next_permutation(b, b + 4)) {
			break;
		}
	}
	cout << res << endl;
	return 0;
}