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

using namespace std;

const long long  int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<vector<int>>v(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> L >> R;
		v[L].push_back((R + N - L) % N);
	}
	for (int i = 1; i <= N; i++) {
		if (v[i].empty())continue;
		sort(v[i].begin(), v[i].end(), greater<int>());
		K = max(K, (long long int)v[i].size());
	}
	for (int i = 1; i <= N; i++) {
		long long int ans = 0;
		for (int j = 1; j <= N; j++) {
			if (v[j].size() == K) {
				ans = max(ans, ((j - i + N) % N) + (K - 1)*N + v[j].back());
			}
			else if (v[j].size() == K - 1 && K - 1) {
				ans = max(ans, ((j - i + N) % N) + (K - 2)*N + v[j].back());
			}
		}
		cout << ans << " ";
	}
	cout << endl;
	return 0;
}