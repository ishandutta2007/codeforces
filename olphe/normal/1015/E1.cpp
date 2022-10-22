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

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 1e-8;

long long int N, M, K, H, W, L, R;

struct Ans {
	int y, x, d;
	void Out() {
		cout << y + 1 << " " << x + 1 << " " << d << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;
	vector<string>s(H);
	vector<Ans>ans;
	int dir[] = { 1,0,-1,0,1 };
	for (int i = 0; i < H; i++)cin >> s[i];
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (s[i][j] == '.')continue;
			int num = 1000;
			for (int k = 0; k < 4; k++) {
				int ny = i;
				int nx = j;
				int box = 0;
				while (1) {
					ny += dir[k];
					nx += dir[k + 1];
					if (ny < 0 || nx < 0 || ny >= H || nx >= W)break;
					if (s[ny][nx] == '.')break;
					box++;
				}
				num = min(num, box);
			}
			if (num)ans.push_back({ i,j,num });
		}
	}
	vector<string>t(H);
	for (int i = 0; i < H; i++) {
		t[i].resize(W,'.');
	}
	for (auto i : ans) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k <= i.d; k++) {
				t[i.y + dir[j] * k][i.x + dir[j + 1] * k] = '*';
			}
		}
	}
	if (s != t) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans.size() << endl;
	for (auto i : ans) {
		i.Out();
	}
	return 0;
}