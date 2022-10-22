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
constexpr long  double EPS = 1e-12;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

void Calculate_Depth(vector<vector<int>>&edge, vector<int>&depth, int stnode) {
	depth[stnode] = 0;
	queue<int>Q;
	Q.push(stnode);
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (auto i : edge[cn]) {
			if (depth[i] > depth[cn] + 1) {
				depth[i] = depth[cn] + 1;
				Q.push(i);
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<vector<int>>edge(N);
	vector<vector<int>>rev(N);
	for (int i = 0; i < M; i++) {
		cin >> L >> R;
		L--, R--;
		edge[L].push_back(R);
		rev[R].push_back(L);
	}
	cin >> K;
	vector<int>v(K);
	for (auto &i : v) {
		cin >> i;
		i--;
	}
	vector<int>dis(N, MOD);
	Calculate_Depth(rev, dis, v.back());
	L = R = 0;
	for (int i = 1; i < v.size(); i++) {
		if (dis[v[i]] >= dis[v[i - 1]])L++;
	}
	vector<int>num(N);
	for (int i = 0; i < N; i++) {
		for (auto j : edge[i]) {
			if (dis[i] > dis[j])num[i]++;
		}
	}
	for (int i = 0; i + 1 < v.size(); i++) {
		if (num[v[i]] > 1||dis[v[i]]<=dis[v[i+1]])R++;
	}
	cout << L << " " << R << endl;
}