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
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-12;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N >> M;
		L = 0;
		R = N * (N - 1) / 2;
		for (int i = 1; i < N; i++) {
			int index = i + 1;
			while (index) {
				L++;
				index >>= 1;
			}
			L--;
		}
		if (L > M || R < M) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		vector<vector<int>>h(N + 1);
		for (int i = 0; i < N; i++) {
			int index = i+1;
			int d = -1;
			while (index) {
				index >>= 1;
				d++;
			}
			h[d].push_back(i);
		}
		while (L != M) {
			for (int i = 1; i < N; i++) {
				if (h[i].size() * 2 >= h[i + 1].size() + 3) {
					h[i + 1].push_back(h[i].back());
					h[i].pop_back();
					L++;
					break;
				}
			}
		}
		vector<int>p(N);
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < h[i].size(); j++) {
				p[h[i][j]] = h[i - 1][j / 2];
			}
		}
		for (int i = 1; i < N; i++)cout << p[i] + 1 << " ";
		cout << endl;
	}

	return 0;
}