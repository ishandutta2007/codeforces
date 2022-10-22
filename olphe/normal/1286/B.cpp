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
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

bool ed = false;

void Search(vector<vector<int>>&edge, vector<vector<int>>&p, vector<int>&num, int node) {
	//cout << node << endl;
	if (ed)return;
	for (auto i : edge[node]) {
		Search(edge, p, num, i);
		if (ed)return;
		for (auto j : p[i])p[node].push_back(j);
	}
	if (p[node].size() < num[node]) {
		ed = true;
		return;
	}
	p[node].insert((p[node].begin() + num[node]), node);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>parent(N);
	vector<vector<int>>edge(N);
	vector<vector<int>>p(N);
	vector<int>num(N);
	int root = 0;
	for (int i = 0; i < N; i++) {
		cin >> L >> R;
		L--;
		parent[i] = L;
		if (L >= 0)edge[L].push_back(i);
		else root = i;
		num[i] = R;
	}
	Search(edge, p, num,root);
	if (ed) {
		cout << "NO\n";
		return 0;
	}
	vector<int>ans(N);
	for (int i = 0; i < N; i++) {
		ans[p[root][i]] = i;
	}
	cout << "YES\n";
	for (auto i : ans)cout << i+1 << " ";
	cout << endl;
}