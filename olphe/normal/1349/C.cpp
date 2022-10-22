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
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W >> K;
	vector<string>s(H);
	for (auto &i : s)cin >> i;
	vector<vector<int>>v(H, vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			v[i][j] = s[i][j] - '0';
		}
	}
	vector<vector<long long int>>dis(H, vector<long long int>(W, MOD*MOD));
	deque<pair<int, int>>Q;
	int dir[] = { 1,0,-1,0,1 };
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			for (int k = 0; k < 4; k++) {
				int ny = i + dir[k], nx = j + dir[k + 1];
				if (ny < 0 || nx < 0 || ny >= H || nx >= W)continue;
				if (v[i][j] == v[ny][nx]) {
					dis[i][j] = 0;
					Q.emplace_back(i, j);
				}
			}
		}
	}
	while (!Q.empty()) {
		int  cy, cx;
		tie(cy, cx) = Q.front();
		Q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i], nx = cx + dir[i + 1];
			if (ny < 0 || nx < 0 || ny >= H || nx >= W)continue;
			if (v[ny][nx] == v[cy][cx]) {
				if (dis[ny][nx] > dis[cy][cx]) {
					dis[ny][nx] = dis[cy][cx];
					Q.emplace_front(ny, nx);
				}
			}
			else {
				if (dis[ny][nx] > dis[cy][cx] + 1) {
					dis[ny][nx] = dis[cy][cx] + 1;
					Q.emplace_back(ny, nx);
				}
			}
		}
	}
	while (K--) {
		cin >> L >> R >> M;
		L--, R--;
		int ret = v[L][R];
		if (M >= dis[L][R] && dis[L][R] % 2 != M % 2)ret ^= 1;
		cout << ret << endl;
	}
};