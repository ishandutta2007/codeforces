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

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<vector<int>>v(N);
	vector<int>in(N);
	for (int i = 0; i < N; i++) {
		cin >> K;
		for(int j=0;j<K;j++){
			int num;
			cin >> num;
			num--;
			v[num].push_back(i);
			in[i]++;
		}
	}
	queue<int>Q;
	vector<int>ans(N, -1);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (in[i] == 0) {
			ans[i] = 1;
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		cnt++;
		int cn = Q.front();
		Q.pop();
		for (auto i : v[cn]) {
			if (i < cn) {
				ans[i] = max(ans[i], ans[cn] + 1);
			}
			else {
				ans[i] = max(ans[i], ans[cn]);
			}
			in[i]--;
			if (in[i] == 0)Q.push(i);
		}
	}
	int ret = *max_element(ans.begin(), ans.end());
	if (cnt < N)cout << -1 << endl;
	else cout << ret << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}