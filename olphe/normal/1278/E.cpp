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
	vector<int>depth(N,MOD);
	Calculate_Depth(edge, depth, 0);
	vector<int>converter(N);
	vector<int>rev(N);
	vector<pair<int, int>>node(N);
	for (int i = 0; i < N; i++) {
		node[i] = { depth[i],i };
	}
	sort(node.begin(), node.end());
	for (int i = 0; i < N; i++) {
		converter[node[i].second] = i;
		rev[i] = node[i].second;
	}
	vector<int>parent(N);
	for (int i = 1; i < N; i++) {
		for (auto j : edge[i]) {
			if (depth[j] < depth[i]) {
				parent[converter[i]] = converter[j];
				break;
			}
		}
	}
	vector<int>inc(N * 2, -1);
	vector<int>dec(N * 2, -1);
	inc[0] = N;
	dec[N] = 0;
	for (int i = 1; i < N; i++) {
		dec[i] = dec[parent[i]];
		dec[parent[i]] = i;
		inc[i] = parent[i];
		if (dec[i] != -1) {
			inc[dec[i]] = i;
		}
		inc[i + N] = inc[parent[i]];
		inc[parent[i]] = i + N;
		dec[i + N] = parent[i];
		if (inc[i + N] != -1) {
			dec[inc[i + N]] = i+N;
		}
	}
	int st = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (dec[i] == -1) {
			st = i;
			break;
		}
	}
	vector<int>place(N * 2);
	int cnt = 1;
	while (st != -1) {
		place[st] = cnt++;
		st = inc[st];
	}
	vector<pair<int, int>>ans(N);
	for (int i = 0; i < N; i++) {
		ans[rev[i]] = { place[i],place[i + N] };
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
}