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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int func(vector<int>v, vector<vector<int>>&edge, int st) {
	vector<int>dir(N);
	vector<queue<int>>Q(3);
	vector<int>used(N);
	for (int i = 0; i < N; i++) {
		dir[i] = edge[i].size();
		if (dir[i] == 1) {
			if (v[i] == 1) {
				Q[1].push(i);
			}
			else if (v[i] == 2) {
				Q[2].push(i);
			}
			else {
				Q[1].push(i);
				Q[2].push(i);
			}
		}
	}
	int turn = 0;
	while (!Q[st].empty()||!Q[st^3].empty()) {
		int add = 0;
		while (!Q[st].empty()) {
			int cn = Q[st].front();
			Q[st].pop();
			if (used[cn])continue;
			used[cn] = 1;
			add = 1;
			for(auto i:edge[cn]){
				dir[i]--;
				if (dir[i] == 1) {
					if (v[i] == 1) {
						Q[1].push(i);
					}
					else if (v[i] == 2) {
						Q[2].push(i);
					}
					else {
						Q[1].push(i);
						Q[2].push(i);
					}
				}
			}
		}
		turn += add;
		st ^= 3;
	}
	return turn;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		vector<int>v(N);
		for (auto &i : v)cin >> i;
		if (N == 1) {
			cout << 1 << endl;
			continue;
		}
		vector<vector<int>>edge(N);
		for (int i = 1; i < N; i++) {
			cin >> L >> R;
			L--, R--;
			edge[L].push_back(R);
			edge[R].push_back(L);
		}
		int ans = MOD;
		for (int i = 1; i <= 2; i++) {
			ans = min(ans, func(v, edge, i));
		}
		cout << ans << endl;
	}
}