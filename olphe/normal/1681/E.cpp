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

constexpr long long int MOD = 1000000007;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<int>ax(N+1);
	vector<int>ay(N+1);
	vector<int>bx(N+1);
	vector<int>by(N+1);
	for (int i = 1; i < N; i++) {
		cin >> ax[i] >> ay[i] >> bx[i] >> by[i];
	}
	vector<vector<vector<vector<long long>>>>dis(20, vector<vector<vector<long long>>>(N, vector<vector<long long>>(2, vector<long long>(2, 1e12))));
	for (int i = 1; i < N; i++) {
		dis[0][i][0][0] = abs(ax[i] - ax[i + 1]) + abs(ay[i] - ay[i + 1]);
		dis[0][i][0][1] = abs(ax[i] - bx[i + 1]) + abs(ay[i] - by[i + 1]);
		if (bx[i + 1] != i + 1 && bx[i] < bx[i + 1])dis[0][i][0][1] += 2;
		dis[0][i][1][0] = abs(bx[i] - ax[i + 1]) + abs(by[i] - ay[i + 1]);
		if (ay[i + 1] != i + 1 && ay[i] < ay[i + 1])dis[0][i][1][0] += 2;
		dis[0][i][1][1] = abs(bx[i] - bx[i + 1]) + abs(by[i] - by[i + 1]);
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < N; j++) {
			if (j + (1 << i) >= N)continue;
			dis[i][j][0][0] = min(dis[i - 1][j][0][0] + dis[i - 1][j + (1 << (i - 1))][0][0], dis[i - 1][j][0][1] + dis[i - 1][j + (1 << (i - 1))][1][0]);
			dis[i][j][0][1] = min(dis[i - 1][j][0][0] + dis[i - 1][j + (1 << (i - 1))][0][1], dis[i - 1][j][0][1] + dis[i - 1][j + (1 << (i - 1))][1][1]);
			dis[i][j][1][0] = min(dis[i - 1][j][1][0] + dis[i - 1][j + (1 << (i - 1))][0][0], dis[i - 1][j][1][1] + dis[i - 1][j + (1 << (i - 1))][1][0]);
			dis[i][j][1][1] = min(dis[i - 1][j][1][0] + dis[i - 1][j + (1 << (i - 1))][0][1], dis[i - 1][j][1][1] + dis[i - 1][j + (1 << (i - 1))][1][1]);
		}
	}
	cin >> K;
	while (K--) {
		int sx, sy, gx, gy;
		cin >> sx >> sy >> gx >> gy;
		if (max(sx, sy) > max(gx, gy)) {
			swap(sx, gx);
			swap(sy, gy);
		}
		if (max(sx, sy) == max(gx, gy)) {
			cout << abs(sx - gx) + abs(sy - gy) << endl;
		}
		else {
			L = max(sx, sy);
			R = max(gx, gy);
			vector<long long>add(2);
			add[0] = abs(ax[L] - sx) + abs(ay[L] - sy);
			add[1] = abs(bx[L] - sx) + abs(by[L] - sy);
			for (int i = 19; i >= 0; i--) {
				if (L + (1 << i) <= R - 1) {
					vector<long long>nx(2, 1e12);
					nx[0] = min(nx[0], add[0] + dis[i][L][0][0]);
					nx[0] = min(nx[0], add[1] + dis[i][L][1][0]);
					nx[1] = min(nx[1], add[0] + dis[i][L][0][1]);
					nx[1] = min(nx[1], add[1] + dis[i][L][1][1]);
					L += 1 << i;
					add = nx;
				}
			}
			long long a = add[0];
			long long b = add[1];
			a += abs(gx - ax[L]) + abs(gy - ay[L]);
			if (gx < R) {
				a += 2;
			}
			b += abs(gx - bx[L]) + abs(gy - by[L]);
			if (gy < R) {
				b += 2;
			}
			cout << min(a, b) << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}