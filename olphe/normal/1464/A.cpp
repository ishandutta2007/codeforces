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

void Solve() {
	cin >> N >> M;
	vector<vector<int>>edge(N);
	vector<int>dir(N);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		if (a != b) {
			edge[a].push_back(b);
			dir[b]++;
		}
	}
	int ans = 0;
	queue<int>Q;
	for (int i = 0; i < N; i++) {
		if (dir[i] == 0)Q.push(i);
	}
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		if (edge[cn].empty())continue;
		ans++;
		dir[edge[cn][0]]--;
		if (dir[edge[cn][0]] == 0) {
			Q.push(edge[cn][0]);
		}
	}
	for (int i = 0; i < N; i++) {
		if (dir[i]) {
			dir[i] = 0;
			Q.push(i);
			ans++;
			while (!Q.empty()) {
				int cn = Q.front();
				Q.pop();
				ans++;
				if (edge[cn].empty())continue;
				dir[edge[cn][0]]--;
				if (dir[edge[cn][0]] == 0) {
					Q.push(edge[cn][0]);
				}
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}