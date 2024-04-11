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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<vector<pair<int, int>>>edge(N);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edge[a].push_back({ c,b });
	}
	for (int i = 0; i < N; i++) {
		if (edge[i].empty()) {
			cout << 0 << endl;
			return 0;
		}
		sort(edge[i].begin(), edge[i].end());
	}
	int box[10][10][10][10] = {};
	vector<vector<pair<int, int>>>in(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < edge[i].size(); j++) {
			in[edge[i][j].second].push_back({ edge[i].size(),j + 1 });
		}
	}
	for (int i = 0; i < N; i++) {
		sort(in[i].begin(), in[i].end());
		for (int j = 1; j < in[i].size(); j++) {
			if (in[i][j] == in[i][j - 1]) {
				box[in[i][j].first][in[i][j].second][in[i][j].first][in[i][j].second] = 1;
			}
		}
		in[i].erase(unique(in[i].begin(), in[i].end()), in[i].end());
		for (int j = 0; j < in[i].size(); j++) {
			for (int k = j + 1; k < in[i].size(); k++) {
				box[in[i][j].first][in[i][j].second][in[i][k].first][in[i][k].second] = 1;
			}
		}
	}
	vector<int>p(K + 1);
	for (int i = 1; i <= K; i++)p[i] = 1;
	int ans = 0;
	while (!p[0]) {
		int add = 1;
		for (int i = 1; i <= K; i++) {
			for (int j = i; j <= K; j++) {
				if (box[i][p[i]][j][p[j]])add = 0;
			}
		}
		ans += add;
	//	for (auto i : p) {
	//		cout << i << " ";
	//	}
	//	cout << endl;
	//	cout << add << endl;
		p.back()++;
		int cnt = K;
		while (p[cnt] > cnt&&cnt) {
			p[cnt] -= cnt;
			cnt--;
			p[cnt]++;
		}
	}
	cout << ans << endl;
}