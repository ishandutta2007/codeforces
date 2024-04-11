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
constexpr long double EPS = 1e-12;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<vector<int>>v(N, vector<int>(N));
	for (auto &i : v)for (auto &j : i)cin >> j;
	vector<vector<vector<pair<int,int>>>>add(N, vector<vector<pair<int,int>>>(N, vector<pair<int,int>>(N)));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				add[i][j][k].first = v[i][k] + v[k][j];
				add[i][j][k].second = k;
			}
			sort(add[i][j].begin(), add[i][j].end());
		}
	}
	int ans = MOD;
	vector<int>w(K / 2);
	vector<int>used(N);
	while (w.front() == 0) {
		//cout << "ok" << endl;
		for (auto i : w)used[i]++;
		int box = 0;
		bool flag = false;
		for (int i = 1; i <= K / 2; i++) {
			if (i == K / 2) {
				for (auto j : add[w.back()][w.front()]) {
					if (used[j.second])continue;
					box += j.first;
					flag = true;
					break;
				}
				break;
			}
			for (auto j : add[w[i - 1]][w[i]]) {
				//cout << j.first << " " << j.second << endl;
				if (used[j.second])continue;
				flag = true;
				box += j.first;
				break;
			}
		}
		if (flag) {
			ans = min(ans, box);
		}
		for (auto i : w)used[i]--;
		w.back()++;
		int index = K / 2 - 1;
		while (w[index] == N) {
			w[index--] = 0;
			w[index]++;
		}
	}
	cout << ans << endl;
	return 0;
}