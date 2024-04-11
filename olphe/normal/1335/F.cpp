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

	int dir[] = { -1,0,1,0,-1 };
	int box[256] = {};
	box['U'] = 0;
	box['R'] = 1;
	box['D'] = 2;
	box['L'] = 3;
	cin >> K;
	while (K--) {
		cin >> H >> W;
		vector<string>c(H);
		for (auto &i : c)cin >> i;
		int blacknum = 0;
		for (auto i : c)for (auto j : i)blacknum += j == '0';
		vector<string>field(H);
		for (auto &i : field)cin >> i;
		vector<vector<vector<pair<int, int>>>>edge(H, vector<vector<pair<int, int>>>(W));
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				int ny = i + dir[box[field[i][j]]];
				int nx = j + dir[box[field[i][j]] + 1];
				edge[ny][nx].push_back({ i,j });
			}
		}
		vector<vector<pair<int, int>>>used(H, vector<pair<int, int>>(W, { -1,-1 }));
		queue<pair<int, int>>Q;
		vector<vector<int>>loop(H, vector<int>(W));
		bool all_loop = true;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (used[i][j].first >= 0)continue;
				all_loop = false;
				used[i][j] = { i,j };
				Q.emplace(i, j);
				while (!Q.empty()) {
					int cy, cx;
					tie(cy, cx) = Q.front();
					Q.pop();
					int ny = cy + dir[box[field[cy][cx]]];
					int nx = cx + dir[box[field[cy][cx]] + 1];
					if (used[ny][nx] == make_pair(i, j)) {
						loop[ny][nx] = 1;
					}
					else if (used[ny][nx].first >= 0) {

					}
					else {
						used[ny][nx] = { i,j };
						Q.emplace(ny, nx);
					}
				}
			}
		}
		field.clear();
		used.clear();
		if (all_loop) {
			cout << H * W << " " << blacknum << endl;
			continue;
		}
		set<pair<pair<int, int>, int>>num;
		set<pair<pair<int, int>, int>>black;
		vector<vector<int>>dis(H, vector<int>(W, -1));
		vector<vector<pair<int, int>>>parent(H, vector<pair<int, int>>(W));
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (!loop[i][j])continue;
				if (dis[i][j] >= 0)continue;
				dis[i][j] = 0;
				Q.emplace(i, j);
				while (!Q.empty()) {
					int cy, cx;
					tie(cy, cx) = Q.front();
					parent[cy][cx] = { i,j };
					Q.pop();
					for (auto k : edge[cy][cx]) {
						int ny, nx;
						tie(ny, nx) = k;
						if (ny == i && nx == j) {
							loop[i][j] = dis[cy][cx] + 1;
						}
						else if (dis[ny][nx] >= 0) {

						}
						else {
							dis[ny][nx] = dis[cy][cx] + 1;
							Q.emplace(ny, nx);
						}
					}
				}
			}
		}
		edge.clear();
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (c[i][j] == '0') {
					black.insert({ parent[i][j],dis[i][j] % loop[parent[i][j].first][parent[i][j].second] });
				}
				num.insert({ parent[i][j],dis[i][j] % loop[parent[i][j].first][parent[i][j].second] });
			}
		}
		cout << num.size() << " " << black.size() << endl;
	}
}