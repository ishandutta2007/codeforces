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
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<unordered_set<int>>st(31);
	for (int i = 0; i < N; i++) {
		cin >> M;
		st[30].insert(M);
	}
	for (int i = 30; i > 0; i--) {
		for (auto j : st[i]) {
			st[i - 1].insert(j / 2);
		}
	}
	vector<unordered_map<int, int>>mp(31);
	for (auto i : st[30]) {
		mp[30][i] = 0;
	}
	for (int i = 29; i >= 0; i--) {
		for (auto j : st[i]) {
			auto a = mp[i + 1].find(j * 2);
			auto b = mp[i + 1].find(j * 2 + 1);
			if (a == mp[i + 1].end()) {
				mp[i][j] = b->second;
			}
			else if (b == mp[i + 1].end()) {
				mp[i][j] = a->second;
			}
			else {
				mp[i][j] = min(a->second, b->second) + (1 << (29 - i));
			}
		}
	}
	cout << mp[0][0] << endl;
}