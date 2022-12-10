//sobskdrbhvk
//remember... ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const int maxn = 2000 + 10;
const int INF = 2e9;
string s[maxn];
deque<pii> deq;
pair<int, pii> dis[maxn][maxn];
bool mark[maxn][maxn];
int n, m,
	r, c,
	x, y;

bool cango(int i, int j) {
	return 0 <= i and i < n and 0 <= j and j < m and s[i][j] == '.';
}

void bfs(void) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dis[i][j] = MP(INF, MP(INF, INF));
	dis[r][c] = MP(0, MP(0, 0));
	deq.push_back(MP(r, c));
	while (sz(deq)) {
		int i = deq.front().L,
			j = deq.front().R;
		deq.pop_front();
		if (mark[i][j])
			continue;
		mark[i][j] = true;
		if (cango(i - 1, j) and !mark[i - 1][j]) {
			deq.push_front(MP(i - 1, j));
			dis[i - 1][j] = dis[i][j];
		}
		if (cango(i + 1, j) and !mark[i + 1][j]) {
			deq.push_front(MP(i + 1, j));
			dis[i + 1][j] = dis[i][j];
		}
		if (cango(i, j - 1) and !mark[i][j - 1] and dis[i][j - 1] > dis[i][j]) {
			dis[i][j - 1] = dis[i][j];
			dis[i][j - 1].L++;
			dis[i][j - 1].R.L++;
			deq.PB(MP(i, j - 1));
		}
		if (cango(i, j + 1) and !mark[i][j + 1] and dis[i][j + 1] > dis[i][j]) {
			dis[i][j + 1] = dis[i][j];
			dis[i][j + 1].L++;
			dis[i][j + 1].R.R++;
			deq.PB(MP(i, j + 1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m
		>> r >> c
		>> x >> y;
	r--, c--;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	bfs();
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (dis[i][j].R.L <= x and dis[i][j].R.R <= y)
				ans++;
	cout << ans << endl;
	return 0;
}