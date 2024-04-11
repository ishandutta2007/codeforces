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

	cin >> N >> M;
	vector<vector<int>>edge(N);
	for (int i = 0; i < M; i++) {
		cin >> L >> R;
		L--, R--;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	vector<int>num(N);
	vector<vector<int>>box(N + 1);
	for (auto &i : num)cin >> i;
	for (int i = 0; i < N; i++) {
		box[num[i]].push_back(i);
	}
	vector<int>ans(N);
	int cnt = 1;
	for (int i = 1; i <= N; i++) {
		for (auto j : box[i]) {
			set<int>st;
			for (auto k : edge[j]) {
				if (ans[k]) {
					st.insert(num[k]);
				}
			}
			int nx = 1;
			for (auto k : st) {
				if (nx == k)nx++;
			}
			if (nx != num[j]) {
				cout << -1 << endl;
				return 0;
			}
			ans[j] = cnt++;
		}
	}
	vector<int>ret(N);
	for (int i = 0; i < N; i++) {
		ret[ans[i] - 1] = i + 1;
	}
	for (auto i : ret)cout << i << " ";
	cout << endl;
}