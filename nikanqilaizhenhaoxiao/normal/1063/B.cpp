#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

const int oo = 1e9;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

char s[2010][2010];
int dpl[2010][2010], dpr[2010][2010];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int r, c;
	scanf("%d%d", &r, &c);
	int x, y;
	scanf("%d%d", &x, &y);
	for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	deque<pair<int, int> > q;

	q.clear();
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) dpl[i][j] = oo;
	dpl[r][c] = 0;
	q.push_back(make_pair(r, c));
	while(!q.empty()) {
		int r = q[0].first, c = q[0].second; q.pop_front();
		for (int k = 0; k < 4; ++k) {
			int x = r + dx[k], y = c + dy[k];
			if(x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] == '.') {
				int z = dpl[r][c];
				if(k == 1) ++z;
				if(z < dpl[x][y]) {
					dpl[x][y] = z;
					if(k == 1) q.push_back(make_pair(x, y));
					else q.push_front(make_pair(x, y));
				}
			}
		}
	}

	q.clear();
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) dpr[i][j] = oo;
	dpr[r][c] = 0;
	q.push_back(make_pair(r, c));
	while(!q.empty()) {
		int r = q[0].first, c = q[0].second; q.pop_front();
		for (int k = 0; k < 4; ++k) {
			int x = r + dx[k], y = c + dy[k];
			if(x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] == '.') {
				int z = dpr[r][c];
				if(k == 2) ++z;
				if(z < dpr[x][y]) {
					dpr[x][y] = z;
					if(k == 2) q.push_back(make_pair(x, y));
					else q.push_front(make_pair(x, y));
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if(s[i][j] == '.') {
		if(j <= c) {
			int dif = c - j;
			int a = dpl[i][j], b = a - dif;
			if(a <= x && b <= y) ++ans;
		}
		else {
			int dif = j - c;
			int b = dpr[i][j], a = b - dif;
			if(a <= x && b <= y) ++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}