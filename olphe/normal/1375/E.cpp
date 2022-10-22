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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	vector<pair<int, int>>w;
	for (int i = 0; i < N; i++) {
		w.push_back({ v[i],i });
	}
	sort(w.begin(), w.end());
	for (int i = 0; i < N; i++) {
		v[w[i].second] = i;
	}
	vector<vector<int>>edge(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (v[i] > v[j])edge[i][j] = 1;
		}
	}
	vector < pair<int, int>>ans;
	for (int i = 0; i < N; i++) {
		vector<pair<int, int>>num;
		for (int j = i + 1; j < N; j++) {
			num.push_back({ v[j],j });
		}
		sort(num.rbegin(), num.rend());
		for (auto j : num) {
			if (edge[i][j.second]) {
				ans.push_back({ i,j.second });
				swap(v[i], v[j.second]);
			}
		}
	}
	cout << ans.size() << endl;
	for (auto i : ans)cout << i.first + 1 << " " << i.second + 1 << endl;
//	for (auto i : v) {
//		cout << i << " ";
//	}
//	cout << endl;
}