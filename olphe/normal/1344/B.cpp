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

	cin >> H >> W;
	vector<string>s(H);
	for (auto &i : s)cin >> i;
	vector<vector<int>>used(H, vector<int>(W, -1));
	int cnt = 0;
	int dir[] = { 1,0,-1,0,1 };
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (used[i][j] != -1)continue;
			if (s[i][j] == '.')continue;
			queue<pair<int, int>>Q;
			Q.emplace(i, j);
			used[i][j] = cnt;
			while (!Q.empty()) {
				int cy = Q.front().first, cx = Q.front().second;
				Q.pop();
				for (int k = 0; k < 4; k++) {
					int ny = cy + dir[k], nx = cx + dir[k + 1];
					if (ny < 0 || nx < 0 || ny >= H || nx >= W)continue;
					if (s[ny][nx] == '.')continue;
					if (used[ny][nx] == cnt)continue;
					used[ny][nx] = cnt;
					Q.emplace(ny, nx);
				}
			}
			cnt++;
		}
	}
	int noh=0, now = 0;
	for (int i = 0; i < H; i++) {
		set<int>st;
		int bef = -1;
		int num = 0;
		for (int j = 0; j < W; j++) {
			if (used[i][j] != -1) {
				st.insert(used[i][j]);
				if (bef == -1)num++;
			}
			bef = used[i][j];
		}
		if (st.size() > 1||st.size()!=num) {
			cout << -1 << endl;
			return 0;
		}
		if (st.size() == 0)noh++;
	}
	for (int j = 0; j < W; j++) {
		set<int>st;
		int bef = -1;
		int num = 0;
		for (int i = 0; i < H; i++) {
			if (used[i][j] != -1) {
				st.insert(used[i][j]);
				if (bef == -1)num++;
			}
			bef = used[i][j];
		}
		if (st.size() > 1 || st.size() != num) {
			cout << -1 << endl;
			return 0;
		}
		if (st.size() == 0)now++;
	}
	noh = !!noh;
	now = !!now;
	if (noh == now) {
		cout << cnt << endl;
	}
	else {
		cout << -1 << endl;
	}

}