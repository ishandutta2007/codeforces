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
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> M;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	vector<string>s(N);
	for (auto& i : s)cin >> i;
	int score = -1;
	vector<int>ans(M);
	for (int i = 0; i < 1 << N; i++) {
		vector<int>sum(N);
		vector<int>point(M);
		int csum = 0;
		vector<pair<int, int>>vp;
		for (int j = 0; j < M; j++) {
			int n = 0;
			for (int k = 0; k < N; k++) {
				if (s[k][j] == '1') {
					if (i >> k & 1) {
						n++;
					}
					else {
						n--;
					}
				}
			}
			vp.push_back({ n,j });
		}
		sort(vp.begin(), vp.end());
		for (int j = 0; j < vp.size(); j++) {
			point[vp[j].second] = j + 1;
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (s[j][k] == '1') {
					sum[j] += point[k];
				}
			}
		}
		for (int j = 0; j < N; j++) {
			csum += abs(v[j] - sum[j]);
		}
		if (csum > score) {
			score = csum;
			ans = point;
		}
	}
	for (auto i : ans)cout << i << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}