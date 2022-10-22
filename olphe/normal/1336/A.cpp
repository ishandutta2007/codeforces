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
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;

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

int Search(vector<vector<int>>&edge, vector<int>&dis, vector<int>&num, int node = 0) {
	for (auto i : edge[node]) {
		if (dis[i] > dis[node]) {
			num[node] += Search(edge, dis, num, i);
		}
	}
	return num[node];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<vector<int>>edge(N);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		L--, R--;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	vector<int>dis(N, MOD);
	Calculate_Depth(edge, dis, 0);
	vector<int>num(N,1);
	Search(edge, dis, num);
	vector<long long int>score(N);
	for (int i = 0; i < N; i++) {
		score[i] = dis[i] - num[i] + 1;
	//	cout << i << " " << num[i] << endl;
		//cout << i << " " << score[i] << endl;
	}
	sort(score.begin(), score.end());
	reverse(score.begin(), score.end());
	long long int ans = 0;
	for (int i = 0; i < K; i++) {
		ans += score[i];
	}
	cout << ans << endl;
}