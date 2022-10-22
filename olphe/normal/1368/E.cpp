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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N >> M;
		vector<vector<int>>edge(N + 1);
		for (int i = 0; i < M; i++) {
			cin >> L >> R;
			edge[L].push_back(R);
		}
		vector<int>dis(N + 1);
		vector<int>ans;
		for (int i = 1; i <= N; i++) {
			if (dis[i] == 2)continue;
			for (auto j : edge[i]) {
				if (dis[j] == 2)continue;
				dis[j] = max(dis[j], dis[i] + 1);
				if (dis[j] == 2) {
					ans.push_back(j);
				}
			}
		}
		sort(ans.begin(), ans.end());
		cout << ans.size() << endl;
		for (auto i : ans)cout << i << " ";
		cout << endl;
	}
}