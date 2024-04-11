#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

const int maxn = 2010, oo = 1e9;

int n;
char s[maxn][maxn];
int f[maxn][maxn], fuck[maxn];
pair<int, int> pre[maxn][maxn];
vector<pair<int, int> > all, foo;

int main() {
	scanf("%d", &n);
	int m; scanf("%d", &m);
	for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	f[1][1] = (s[1][1] == 'a' ? 0 : 1);
	if(m < f[1][1]) {
		putchar(s[1][1]);
		all.push_back(make_pair(1, 1));
	}
	else {
		int lst = 2;
		for (int k = 3; k <= n + n; ++k) {
			for (int i = 1; i <= n; ++i) {
				int j = k - i;
				if(j >= 1 && j <= n) {
					f[i][j] = oo;
					if(i > 1) f[i][j] = min(f[i][j], f[i - 1][j] + (s[i][j] == 'a' ? 0 : 1));
					if(j > 1) f[i][j] = min(f[i][j], f[i][j - 1] + (s[i][j] == 'a' ? 0 : 1));
					if(f[i][j] <= m) lst = k;
				}
			}
		}
		for (int i = 2; i <= lst; ++i) putchar('a');
		if(lst == n + n) return 0;
		for (int i = 1; i <= n; ++i) {
			int j = lst - i;
			if(j >= 1 && j <= n && f[i][j] <= m) all.push_back(make_pair(i, j));
		}
	}
	int T = 0;
	for(;;) {
		if(all[0].first == n && all[0].second == n) break;
		char mn = 'z' + 1;
		for (auto p: all) {
			int x = p.first, y = p.second;
			if(x + 1 <= n) mn = min(mn, s[x + 1][y]);
			if(y + 1 <= n) mn = min(mn, s[x][y + 1]);
		}
		foo.clear();
		++T;
		for (auto p: all) {
			int x = p.first, y = p.second;
			if(x + 1 <= n && s[x + 1][y] == mn) {
				if(fuck[x + 1] != T) fuck[x + 1] = T, foo.push_back(make_pair(x + 1, y)), pre[x + 1][y] = p;
			}
			if(y + 1 <= n && s[x][y + 1] == mn) {
				if(fuck[x] != T) fuck[x] = T, foo.push_back(make_pair(x, y + 1)), pre[x][y + 1] = p;
			}
		}
		all = foo;
	}
	vector<char> ans;
	for (int x = n, y = n; x && y; ) {
		auto t = pre[x][y];
		if(!t.first || !t.second) break;
		ans.push_back(s[x][y]);
		x = t.first, y = t.second;
	}
	reverse(ans.begin(), ans.end());
	for (auto c: ans) putchar(c);
	putchar('\n');
	return 0;
}