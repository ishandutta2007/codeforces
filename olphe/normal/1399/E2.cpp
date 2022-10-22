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

void Search(vector<vector<int>>&edge, vector<int>&weight, vector<int>&depth, int node = 0) {
	for (auto i : edge[node]) {
		if (depth[i] < depth[node])continue;
		Search(edge, weight, depth, i);
		weight[node] += weight[i];
	}
	if (weight[node] == 0)weight[node]++;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int loop;
	cin >> loop;
	while (loop--) {
		cin >> N >> M;
		vector<vector<int>>edge(N);
		map<pair<int, int>, pair<int, int>>mp;
		for (int i = 1; i < N; i++) {
			cin >> L >> R >> K >> H;
			L--, R--;
			edge[L].push_back(R);
			edge[R].push_back(L);
			mp[{min(L, R), max(L, R)}] = { K ,H };
		}
		vector<int>depth(N, MOD);
		Calculate_Depth(edge, depth, 0);
		vector<int>weight(N);
		Search(edge, weight, depth);
		long long int sum = 0;
		priority_queue<pair<long long int, pair<long long int, long long int>>>PQ[3];
		for (int i = 0; i < N; i++) {
			for (auto j : edge[i]) {
				if (i > j)continue;
				long long int box = mp[{i, j}].first;
				if (depth[i] > depth[j]) {
					sum += box * weight[i];
					if (box > 0)PQ[mp[{i, j}].second].push({ (box - box / 2)*weight[i] ,{box,weight[i]} });
				}
				else {
					sum += box * weight[j];
					if (box > 0)PQ[mp[{i, j}].second].push({ (box - box / 2)*weight[j] ,{ box,weight[j] } });
				}
			}
		}
		int ans = 0;
		while (sum > M) {
			if (PQ[1].empty()) {
				ans += 2;
				auto box = PQ[2].top();
				PQ[2].pop();
				sum -= box.first;
				box.second.first >>= 1;
				box.first = (box.second.first - box.second.first / 2)*box.second.second;
				PQ[2].push(box);
			}
			else if (PQ[2].empty()) {
				ans += 1;
				auto box = PQ[1].top();
				PQ[1].pop();
				sum -= box.first;
				box.second.first >>= 1;
				box.first = (box.second.first - box.second.first / 2)*box.second.second;
				PQ[1].push(box);
			}
			else {
				auto box = PQ[1].top();
				PQ[1].pop();
				if (sum - box.first <= M) {
					ans++;
					break;
				}
				long long int num = box.first;
				if (PQ[1].empty()) {
					num += (box.second.first / 2 - box.second.first / 2 / 2)*box.second.second;
				}
				else {
					num += max((box.second.first / 2 - box.second.first / 2 / 2)*box.second.second, PQ[1].top().first);
				}
				if (num < PQ[2].top().first) {
					PQ[1].push(box);
					box = PQ[2].top();
					PQ[2].pop();
					sum -= box.first;
					box.second.first >>= 1;
					box.first = (box.second.first - box.second.first / 2)*box.second.second;
					PQ[2].push(box);
					ans += 2;

				}
				else {
					ans++;
					sum -= box.first;
					box.second.first >>= 1;
					box.first = (box.second.first - box.second.first / 2)*box.second.second;
					PQ[1].push(box);
				}
			}
		}
		cout << ans << endl;
	}
}