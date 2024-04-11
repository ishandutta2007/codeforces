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

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<vector<int>>edge(N);
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < M; i++) {
		cin >> L >> R;
		L--, R--;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	vector<int>parent(N, -1);
	vector<int>dis(N, MOD);
	for (int i = 0; i < N; i++) {
		if (dis[i] != MOD)continue;
		dis[i] = 0;
		parent[i] = i;
		queue<int>Q;
		Q.push(i);
		while (!Q.empty()) {
			int cn = Q.front();
			Q.pop();
			for (auto j : edge[cn]) {
				if (dis[j] > dis[cn] + 1) {
					dis[j] = dis[cn] + 1;
					parent[j] = i;
					Q.push(j);
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (auto j : edge[i]) {
			if (dis[i] % 2 == dis[j] % 2) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	vector<bitset<5001>>bs(N+1);
	bs[0].flip(0);
	vector<vector<int>>odd(N);
	vector<vector<int>>even(N);
	for (int i = 0; i < N; i++) {
		if (dis[i] & 1) {
			odd[parent[i]].push_back(i);
		}
		else {
			even[parent[i]].push_back(i);
		}
	}
	for (int i = 0; i < N; i++) {
		bs[i + 1] = bs[i];
		if (i != parent[i])continue;
		bs[i+1] = (bs[i] << odd[i].size()) | (bs[i] << even[i].size());
	}
	if (bs.back().test(b)) {
		cout << "YES\n";
		string ans(N, '2');
		int num = b;
		for (int i = N - 1; i >= 0; i--) {
			if (i != parent[i])continue;
			if (num >= odd[i].size() && bs[i].test(num - odd[i].size())) {
				for (auto j : even[i])ans[j] = '1';
				num -= odd[i].size();
			}
			else {
				for (auto j : odd[i])ans[j] = '1';
				num -= even[i].size();
			}
		}
		for (auto &i : ans) {
			if (i == '1'&&c) {
				i = '3';
				c--;
			}
		}
		cout << ans << endl;
	}
	else {
		cout << "NO\n";
		return 0;
	}
}