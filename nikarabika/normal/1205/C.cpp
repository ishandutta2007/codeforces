//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<pii, pii> piiii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 50 + 5;
bool dp[maxn][maxn][maxn][maxn],
	 pd[maxn][maxn][maxn][maxn],
	 a[maxn][maxn],
	 b[maxn][maxn],
	 mark[maxn][maxn];
int n;

int dx[] = {2, 1, 0, -2},
	dy[] = {0, 1, 2, 0};

bool is_valid(int x, int y) {
	return 0 <= x and x < n
		and 0 <= y and y < n;
}

int ask(int x, int y, int xx, int yy) {
	if (x > xx or y > yy)
		swap(x, xx), swap(y, yy);
	cout << "? " << x+1 << ' ' << y+1 << ' ' << xx+1 << ' ' << yy+1 << endl;
	int ans;
	cin >> ans;
	return ans;
}

void dfs(int x, int y) {
	mark[x][y] = true;
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (!is_valid(nx, ny) or mark[nx][ny])
			continue;
		a[nx][ny] = ask(x, y, nx, ny) ^ a[x][y] ^ 1;
		dfs(nx, ny);
	}
}

vector<pii> srcadj(pii src) {
	vector<pii> result;
	if (src.L)
		result.PB(MP(src.L - 1, src.R));
	if (src.R)
		result.PB(MP(src.L, src.R - 1));
	return result;
}

vector<pii> dstadj(pii src) {
	vector<pii> result;
	if (src.L + 1 < n)
		result.PB(MP(src.L + 1, src.R));
	if (src.R + 1 < n)
		result.PB(MP(src.L, src.R + 1));
	return result;
}

void calc(bool arr[][maxn], bool pal[][maxn][maxn][maxn]) {
	vector<piiii> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			q.PB(MP(MP(i, j), MP(i, j)));
			pal[i][j][i][j] = true;
			if (i and arr[i - 1][j] == arr[i][j]) {
				q.PB(MP(MP(i - 1, j), MP(i, j)));
				pal[i - 1][j][i][j] = true;
			}
			if (j and arr[i][j - 1] == arr[i][j]) {
				q.PB(MP(MP(i, j - 1), MP(i, j)));
				pal[i][j - 1][i][j] = true;
			}
		}
	for (int i = 0; i < sz(q); i++) {
		auto src = q[i].L;
		auto dst = q[i].R;
		for (auto nsrc : srcadj(src))
			for (auto ndst : dstadj(dst)) {
				if (!pal[nsrc.L][nsrc.R][ndst.L][ndst.R] and arr[nsrc.L][nsrc.R] == arr[ndst.L][ndst.R]) {
					pal[nsrc.L][nsrc.R][ndst.L][ndst.R] = true;
					q.PB(MP(nsrc, ndst));
				}
			}
	}
}

void print(bool a[][maxn]) {
	cout << "!\n";
	for (int i = 0; i < n; i++, cout << '\n')
		for (int j = 0; j < n; j++)
			cout << a[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	a[0][0] = 1;
	dfs(0, 0);
	dfs(1, 0);
	memcpy(b, a, sizeof a);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((i+j)&1)
				b[i][j] ^= 1;
	calc(a, dp);
	calc(b, pd);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int ii = i; ii < n; ii++)
				for (int jj = j; jj < n; jj++)
					if (i + j + 2 <= ii + jj and dp[i][j][ii][jj] != pd[i][j][ii][jj]) {
						int val = ask(i, j, ii, jj);
						if (dp[i][j][ii][jj] == val)
							print(a);
						else
							print(b);
						return 0;
					}
	return 0;
}