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

using namespace std;

const long long  int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int dir[] = { 0,1,0,-1,0 };
	cin >> H >> W >> K;
	vector<string>s(H);
	for (auto &i : s)cin >> i;
	vector<vector<int>>used(H, vector<int>(W, 0));
	for (int i = 0; i < K; i++) {
		int h, w;
		cin >> h >> w;
		h--;
		w--;
		if (used[h][w]) {
			cout << used[h][w] << endl;
			continue;
		}
		queue<pair<int, int>>Q;
		vector<pair<int, int>>box;
		Q.push({ h,w });
		int add = 0;
		used[h][w] = -1;
		while (!Q.empty()) {
			auto cn = Q.front();
			Q.pop();
			box.push_back(cn);
			add += 4;
			for (int j = 0; j < 4; j++) {
				int ny = cn.first + dir[j];
				int nx = cn.second + dir[j + 1];
				if (s[ny][nx] == '*')continue;
				add--;
				if (used[ny][nx])continue;
				used[ny][nx] = -1;
				Q.push({ ny,nx });
			}
		}
		for (auto j : box)used[j.first][j.second] = add;
		cout << add << endl;
	}
	return 0;
}