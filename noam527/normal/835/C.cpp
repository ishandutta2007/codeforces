#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define last(X) (X)[(X).size() - 1]
#define last(x, y) (x)[(x).size() - y]
typedef long long ll;
using namespace std;

struct query {
	int t, x1, x2, y1, y2, ind;
	bool operator <(const query &a) {
		return t < a.t;
	}
};
struct point {
	int x, y, s;
};

int n, q, c, dp[102][102], board[102][102];
vector<point> p;
vector<query> a;
vector<int> output;

void makedp() {
	for (int i = 0; i < 102; i++) dp[i][0] = dp[0][i] = 0;
	for (int i = 1; i < 102; i++) for (int j = 1; j < 102; j++)
		dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + board[i][j];
}

void update(int t) {
	for (int i = 0; i < 102; i++) for (int j = 0; j < 102; j++) board[i][j] = 0;
	for (auto &i : p) {
		i.s = (i.s + t) % (c + 1);
		board[i.x][i.y] += i.s;
	}
	makedp();
}

void answer(query &que) {
	output[que.ind] = dp[que.x2][que.y2] - dp[que.x1 - 1][que.y2] - dp[que.x2][que.y1 - 1] + dp[que.x1 - 1][que.y1 - 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> q >> c;
	p.resize(n), a.resize(q), output.resize(q);
	for (int i = 0, x, y, s; i < n; i++) cin >> p[i].x >> p[i].y >> p[i].s;
	for (int i = 0; i < q; i++) cin >> a[i].t >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2, a[i].t %= (c + 1), a[i].ind = i;
	sort(a.begin(), a.end());
	update(a[0].t), answer(a[0]);
	for (int i = 1; i < q; i++) {
		if (a[i].t != a[i - 1].t) update(a[i].t - a[i - 1].t);
		answer(a[i]);
	}
	for (auto &i : output) cout << i << endl;
	return 0;
}