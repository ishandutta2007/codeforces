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
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int dist(pair<int, pair<int, pair<int, int>>>a, pair<int, pair<int, pair<int, int>>>b) {
	return abs(a.first - b.first) + abs(a.second.first - b.second.first) + abs(a.second.second.first - b.second.second.first);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<pair<int, pair<int, pair<int,int>>>>v(N);
	int cnt = 0;
	for (auto &i : v) {
		cin >> i.first >> i.second.first >> i.second.second.first;
		i.second.second.second = ++cnt;
	}
	vector<int>used(N);
	for (int i = 0; i < N; i++) {
		if (used[i])continue;
		used[i] = 1;
		int nx = -1;
		for (int j = i + 1; j < N; j++) {
			if (used[j])continue;
			if (nx == -1)nx = j;
			else if (dist(v[i], v[nx]) > dist(v[i], v[j])) {
				nx = j;
			}
		}
		used[nx] = 1;
		cout << v[i].second.second.second << " " << v[nx].second.second.second << endl;
	}
}