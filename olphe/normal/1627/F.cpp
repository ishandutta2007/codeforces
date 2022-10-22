#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> H;
	W = H;
	vector<vector<int>>yoko(H + 1, vector<int>(W + 1));
	vector<vector<int>>tate(H + 1, vector<int>(W + 1));
	for (int i = 0; i < N; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--, b--, c--, d--;
		if (a == c) {
			yoko[a][min(b, d)]++;
		}
		else {
			tate[min(a, c)][b]++;
		}
	}
	vector<vector<int>>dis(H + 1, vector<int>(W + 1, MOD));
	dis[H / 2][W / 2] = 0;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>PQ;
	PQ.push({ 0,{H / 2,W / 2} });
	while (!PQ.empty()) {
		int cost;
		pair<int, int>p;
		tie(cost, p) = PQ.top();
		PQ.pop();
		int y, x;
		tie(y, x) = p;
	//	cout << y << " " << x << " " << cost << endl;
		if (y == 0 || x == 0 || y == H || x == W)continue;
		if (dis[y][x] < cost)continue;
		if (y&&x) {
			int add = yoko[y - 1][x - 1] + yoko[H - y][W - x - 1];
			int ny = y - 1;
			int nx = x;
			if (dis[ny][nx] > cost + add) {
				dis[ny][nx] = cost + add;
				PQ.push({ cost + add,{ny,nx} });
			}
		}
		if (x&&y) {
			int add = tate[y - 1][x - 1] + tate[H - y - 1][W - x];
			int ny = y;
			int nx = x - 1;
			if (dis[ny][nx] > cost + add) {
				dis[ny][nx] = cost + add;
				PQ.push({ cost + add,{ny,nx} });
			}
		}
		if (y + 1 <= H&&x) {
			int add = yoko[y][x - 1] + yoko[H - y - 1][W - x - 1];
			int ny = y + 1;
			int nx = x;
			if (dis[ny][nx] > cost + add) {
				dis[ny][nx] = cost + add;
				PQ.push({ cost + add,{ny,nx} });
			}
		}
		if (x + 1 <= W&&y) {
			int add = tate[y - 1][x] + tate[H - y - 1][W - x - 1];
			int ny = y;
			int nx = x + 1;
			if (dis[ny][nx] > cost + add) {
				dis[ny][nx] = cost + add;
				PQ.push({ cost + add,{ny,nx} });
			}
		}
	}
	int ans = MOD;
	for (int i = 0; i <= H; i++) {
		ans = min(ans, dis[0][i]);
		ans = min(ans, dis[H][i]);
		ans = min(ans, dis[i][0]);
		ans = min(ans, dis[i][H]);
	}
	cout << N - ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}