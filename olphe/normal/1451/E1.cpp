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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<vector<int>>box(N);
	vector<int>v(N);
	for (int i = 1; i < N; i++) {
		cout << "XOR " << 1 << " " << i + 1 << endl;
		cin >> v[i];
		box[v[i]].push_back(i);
	}
	if (!box[0].empty()) {
		int idx = box[0][0];
		cout << "AND " << 1 << " " << idx + 1 << endl;
		int st;
		cin >> st;
		cout << "!";
		for (int i = 0; i < N; i++) {
			cout << " " << (st ^ v[i]);
		}
		cout << endl;
		return 0;
	}
	int st = 0;
	bool flag = true;
	for (int i = 1; i < N; i++) {
		if (box[i].size() > 1) {
			flag = false;
			cout << "AND " << box[i][0] + 1 << " " << box[i][1] + 1 << endl;
			cin >> st;
			st ^= v[box[i][0]];
			break;
		}
	}
	if (flag) {
		cout << "AND " << 1 << " " << box[1][0] + 1 << endl;
		int a;
		cin >> a;
		cout << "AND " << 1 << " " << box[2][0] + 1 << endl;
		int b;
		cin >> b;
		a >>= 1;
		a <<= 1;
		a |= b & 1;
		st = a;
	}
	cout << "!";
	for (int i = 0; i < N; i++) {
		cout << " " << (st ^ v[i]);
	}
	cout << endl;
}