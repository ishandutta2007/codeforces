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

	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	vector<vector<int>>ans(N);
	queue<int>Q;
	queue<int>yQ;
	queue<int>xQ;
	for (int i = N - 1; i >= 0; i--) {
		if (v[i] == 1) {
			ans[i].push_back(i);
			Q.push(i);
		}
		else if (v[i] == 2) {
			if (yQ.empty()&&Q.empty()) {
				cout << -1 << endl;
				return 0;
			}
			if (!yQ.empty()) {
				ans[i].push_back(yQ.front());
				yQ.pop();
			}
			else {
				ans[i].push_back(Q.front());
				Q.pop();
			}
			xQ.push(i);
		}
		else if (v[i] == 3) {
			if (xQ.empty()&&Q.empty()) {
				cout << -1 << endl;
				return 0;
			}
			if (!xQ.empty()) {
				ans[i].push_back(i);
				ans[xQ.front()].push_back(i);
				xQ.pop();
			}
			else {
				ans[i].push_back(i);
				ans[Q.front()].push_back(i);
				Q.pop();
			}
			xQ.push(i);
		}
	}
	vector<pair<int, int>>ret;
	for (int i = 0; i < N; i++) {
		for (auto j : ans[i])ret.push_back({ i + 1,j + 1 });
	}
	cout << ret.size() << endl;
	for (auto i : ret)cout << i.second << " " << i.first << endl;
}