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
#include "functional"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

list<int> Prime(int num) {
	list<int>P;
	for (int i = 5; i <= num; i += 6) {
		bool flag = true;
		for (auto j : P) {
			if (j*j > i) {
				break;
			}
			if (i%j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i);
		flag = true;
		for (auto j : P) {
			if (j*j > i + 2) {
				break;
			}
			if ((i + 2) % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i + 2);
	}
	P.push_front(3);
	P.push_front(2);
	return P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	auto P = Prime(1000000);

	cin >> N;

	vector<vector<int>>edge(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		edge[i][(i + 1) % N] = 1;
		edge[(i + 1) % N][i] = 1;
	}
	vector<int>isp(1000001);
	for (const auto& i : P)isp[i] = 1;
	M = N;
	int st = 0;
	while (!isp[M]) {
		int to = st + 2;
		if (to >= N)break;
		edge[st][to] = 1;
		st++;
		if (st % 4 == 2)st += 2;
		M++;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (edge[i][j])ans++;
		}
	}
	cout << ans << endl;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (edge[i][j])cout << i + 1 << " " << j + 1 << endl;
		}
	}
}