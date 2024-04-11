#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int r, n, nim[101][4];
vector<pair<int, int>> a;

int mex(const vector<int> &b) {
	static bool exist[300];
	for (int i = 0; i < 300; i++) exist[i] = false;
	for (const auto &i : b) exist[i] = true;
	for (int i = 0; i < 300; i++) if (!exist[i]) return i;
}

void pre() {
	for (int i = 0; i < 4; i++) nim[0][i] = 0, nim[1][i] = 1, nim[2][i] = 0;
	nim[1][3] = 0;
	nim[2][1] = 2;
	nim[2][3] = 1;

	nim[3][0] = 1, nim[3][1] = 3, nim[3][2] = 1, nim[3][3] = 0;

	vector<int> tmp;
	for (int k = 4; k <= r; k++) {
		// case 0
		tmp.clear();
		for (int x = 0; x < k; x++)
			tmp.push_back(nim[x][1] ^ nim[k - x - 1][1]);
		nim[k][0] = mex(tmp);
		// case 1
		tmp.clear();
		tmp.push_back(nim[k - 1][1]);
		tmp.push_back(nim[k - 2][1]);
		tmp.push_back(nim[1][1] ^ nim[k - 2][1]);
		for (int x = 2; x < k - 2; x++) {
			tmp.push_back(nim[x][3] ^ nim[k - x - 1][1]);
			tmp.push_back(nim[x][2] ^ nim[k - x - 1][1]);
		}
		nim[k][1] = mex(tmp);
		// case 2
		tmp.clear();
		tmp.push_back(nim[k - 1][2]);
		tmp.push_back(nim[k - 2][3]);
		tmp.push_back(nim[1][1] ^ nim[k - 2][2]);
		for (int x = 2; x < k - 2; x++) {
			tmp.push_back(nim[x][3] ^ nim[k - x - 1][3]);
			tmp.push_back(nim[x][2] ^ nim[k - x - 1][2]);
		}
		nim[k][2] = mex(tmp);
		// case 3
		tmp.clear();
		tmp.push_back(nim[k - 1][3]);
		tmp.push_back(nim[k - 2][2]);
		tmp.push_back(nim[1][1] ^ nim[k - 2][3]);
		for (int x = 2; x < k - 2; x++)
			tmp.push_back(nim[x][2] ^ nim[k - x - 1][3]);
		nim[k][3] = mex(tmp);
	}
}

int main() {
	fast;
	cin >> r >> n;
	pre();
//	for (int i = 0; i <= 10; i++) {
//		for (int j = 0; j < 4; j++) cout << nim[i][j] << " "; cout << endl;
//	}
//	return 0;
	a.resize(n);
	for (auto &i : a) cin >> i.first >> i.second;

	int board[102] = {};
	for (const auto &i : a) {
		board[i.first] |= 3;
		board[i.first - 1] |= i.second;
		board[i.first + 1] |= i.second;
	}
	vector<pair<int, int>> states;
	int fst = 0, lst = 0;
	int start = 1;
	for (int i = 1; i <= r; i++) {
		if (i == start && board[i] == 3) start++;
		else if (i == start && board[i] != 3)
			fst = board[i];
		else if (board[i] == 3) {
			int len = i - start;
			int val;
			if (fst == 0 && board[i - 1] == 0) val = 0;
			else if (fst == 0 || board[i - 1] == 0) val = 1;
			else if (fst == board[i - 1]) val = 2;
			else val = 3;
			states.push_back({ len, val });
			start = i + 1;
		}
	}
	if (start != r + 1) {
		int len = r + 1 - start;
		int val;
		if (fst == 0 && board[r] == 0) val = 0;
		else if (fst == 0 || board[r] == 0) val = 1;
		else if (fst == board[r]) val = 2;
		else val = 3;
		states.push_back({ len, val });
	}

	int x = 0;
	for (const auto &i : states) x ^= nim[i.first][i.second];

//	for (const auto &i : states) cout << i.first << " " << i.second << endl;

	cout << (x == 0 ? "LOSE" : "WIN") << endl;
}