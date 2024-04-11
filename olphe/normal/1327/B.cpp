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

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		vector<vector<int>>v(N);
		vector<int>p(N);
		vector<int>used(N);
		for (int i = 0; i < N; i++) {
			cin >> M;
			v[i].resize(M);
			for (auto &j : v[i]) {
				cin >> j;
				j--;
			}
			for (auto j : v[i]) {
				if (used[j])continue;
				used[j] = 1;
				p[i] = 1;
				break;
			}
		}
		if (accumulate(used.begin(), used.end(), 0) == N)cout << "OPTIMAL\n";
		else {
			cout << "IMPROVE\n";
			for (int i = N - 1; i >= 0; i--) {
				if (p[i])continue;
				cout << i + 1 << " ";
				break;
			}
			for (int i = N - 1; i >= 0; i--) {
				if (used[i])continue;
				cout << i + 1 << endl;
				break;
			}
		}
	}
}