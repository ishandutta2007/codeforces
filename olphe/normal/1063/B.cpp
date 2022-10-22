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
#include "bitset"

using namespace std;

//const long long int MOD = 998244353;
const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;
	int sy, sx;
	cin >> sy >> sx;
	sy--;
	sx--;
	cin >> L >> R;
	vector<string>s(H);
	for (auto &i : s)cin >> i;
	vector<vector<int>>ldis(H, vector<int>(W, MOD));
	ldis[sy][sx] = 0;
	deque<pair<int,int>>Q;
	Q.push_back({ sy,sx });
	int dir[] = { 1,0,-1,0,1 };
	while (!Q.empty()) {
		int cy = Q.front().first;
		int cx = Q.front().second;
		Q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dir[i];
			int nx = cx + dir[i + 1];
			if (ny < 0 || nx < 0 || ny >= H || nx >= W)continue;
			if (s[ny][nx] == '*')continue;
			if (i == 1) {
				if (ldis[ny][nx] > ldis[cy][cx] + 1) {
					ldis[ny][nx] = ldis[cy][cx] + 1;
					Q.push_back({ ny,nx });
				}
			}
			else {
				if (ldis[ny][nx] > ldis[cy][cx]) {
					ldis[ny][nx] = ldis[cy][cx];
					Q.push_front({ ny,nx });
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (s[i][j] == '*')continue;
			if (ldis[i][j] <= L && j - sx + ldis[i][j] <= R)ans++;
		}
	}
	cout << ans << endl;
	return 0;
}