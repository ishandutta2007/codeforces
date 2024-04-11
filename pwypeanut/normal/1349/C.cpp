#include <bits/stdc++.h>
using namespace std;

int N, M, Q1;
queue< pair< int, pair<int, int> > > Q; 
int d[1005][1005], dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
char s[1005][1005];
bool stagnant = 0;

bool cv(int x, int y) {
	if (x < 0 || x >= N) return false;
	if (y < 0 || y >= M) return false;
	return true;
}

int main() {
	scanf("%d%d%d", &N, &M, &Q1);
	for (int i = 0; i < N; i++) scanf("%s", s[i]);
	memset(d, -1, sizeof(d));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int diff = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dir[k][0], ny = j + dir[k][1];
				if (cv(nx, ny) && s[nx][ny] == s[i][j]) diff++;
			}
			if (diff != 0) {
				d[i][j] = 0;
				Q.push(make_pair(0,make_pair(i,j)));
			}
		}
	}
	if (Q.size() == 0) stagnant = 1;
	while (!Q.empty()) {
		int x = Q.front().second.first, y = Q.front().second.second, dis = Q.front().first;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0], ny = y + dir[i][1];
			if (cv(nx, ny) && d[nx][ny] == -1) {
				d[nx][ny] = dis + 1; 
				Q.push(make_pair(dis+1, make_pair(nx, ny)));
			}
		}
	}
	for (int i = 0; i < Q1; i++) {
		int a, b;
		long long c;
		scanf("%d%d%lld", &a, &b, &c);
		a--;
		b--;
		if (stagnant) {
			printf("%c\n", s[a][b]);
		} else {
			if (c < d[a][b]) {
				printf("%c\n", s[a][b]);
			} else printf("%c\n", s[a][b] ^ (int)((c - d[a][b]) % 2));
		}
	}
}