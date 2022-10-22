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
#include "ctime"
#include "complex"
using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
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
	vector<vector<int>>edge(N + 1);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	vector<int>depth(N + 1, MOD);
	set<pair<int, int>>s;
	Calculate_Depth(edge, depth, 1);
	for (int i = 1; i <= N; i++) {
		if(depth[i]>2)s.insert({ -depth[i],i });
	}
	int ans = 0;
	while(!s.empty()){
		ans++;
		auto box = *s.begin();
		for (auto j : edge[box.second]) {
			if (depth[j] + 1 == depth[box.second]) {
				for (auto k : edge[j]) {
					s.erase({ -depth[k],k });
				}
				s.erase({ -depth[j],j});
			}
		}
	}
	cout << ans << endl;
	return 0;
}