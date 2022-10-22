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
constexpr long  double EPS = 1e-8;

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

	cin >> N;
	vector<vector<int>>edge(N);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		L--, R--;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	int sz = N;
	int tp = 0;
	vector<int>flag(N, true);
	while (sz > 1) {
		vector<int>adis(N, MOD);
		Calculate_Depth(edge, adis, tp);
		int bt = tp;
		for (int i = 0; i < N; i++) {
			if (adis[i] == MOD)flag[i] = 0;
			else if (adis[bt] < adis[i])bt = i;
		}
		vector<int>bdis(N, MOD);
		Calculate_Depth(edge, bdis, bt);
		int cn = bt;
		for (int j = 0; j < N; j++) {
			if (flag[j] && bdis[cn] < bdis[j])cn = j;
		}
		for (auto &i : adis)i = MOD;
		Calculate_Depth(edge, adis, cn);
		cout << "? " << bt + 1 << " " << cn + 1 << endl;
		cin >> K;
		K--;
		tp = K;
		if (K == bt) break;
		if (K == cn)break;
		for (int i = 0; i < edge[tp].size(); i++) {
			if (adis[tp] + bdis[tp] == adis[edge[tp][i]] + bdis[edge[tp][i]]) {
				swap(edge[tp][i], edge[tp][edge[tp].size() - 1]);
				edge[tp].pop_back();
				break;
			}
		}
		for (int i = 0; i < edge[tp].size(); i++) {
			if (adis[tp] + bdis[tp] == adis[edge[tp][i]] + bdis[edge[tp][i]]) {
				swap(edge[tp][i], edge[tp][edge[tp].size() - 1]);
				edge[tp].pop_back();
				break;
			}
		}
		vector<int>cdis(N, MOD);
		Calculate_Depth(edge, cdis, tp);
		for (int i = 0; i < N; i++) {
			if (cdis[i] == MOD)flag[i] = 0;
		}
		sz = accumulate(flag.begin(), flag.end(), 0);
	}
	cout << "! " << tp + 1 << endl;
}