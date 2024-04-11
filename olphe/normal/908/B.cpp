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
#include "iomanip"
#include "cmath"
#include "random"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;
	vector<string>s(H);
	for (int i = 0; i < H; i++) {
		cin >> s[i];
	}
	string t;
	cin >> t;

	int sy, sx, gy, gx;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (s[i][j] == 'S') {
				sy = i;
				sx = j;
			}
			if (s[i][j] == 'E') {
				gy = i;
				gx = j;
			}
		}
	}
	int dy[4] = { 1,0,-1,0 };
	int dx[4] = { 0,1,0,-1 };
	vector<int>v(4);
	for (int i = 0; i < 4; i++) {
		v[i] = i;
	}
	while (1) {
		int cy = sy;
		int cx = sx;
		bool flag = false;
		for (auto i : t) {
			cy += dy[v[i - '0']];
			cx += dx[v[i - '0']];
			if (cy < 0 || cx < 0 || cy >= H || cx >= W) {
				flag = false;
				break;
			}
			if (s[cy][cx] == '#') {
				flag = false;
				break;
			}
			if (s[cy][cx] == 'E') {
				flag = true;
				break;
			}
		}
		if (flag) {
			M++;
		}
		if (!next_permutation(v.begin(), v.end())) {
			break;
		}
	}
	cout << M << endl;
	return 0;
}