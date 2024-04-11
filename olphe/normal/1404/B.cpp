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

	cin >> T;
	while (T--) {
		cin >> N;
		int sa, sb, ja, jb;
		cin >> sa >> sb >> ja >> jb;
		sa--, sb--;
		vector<vector<int>>edge(N);
		for (int i = 1; i < N; i++) {
			cin >> L >> R;
			L--, R--;
			edge[L].push_back(R);
			edge[R].push_back(L);
		}
		if (jb <= ja * 2) {
			cout << "Alice" << endl;
			continue;
		}
		vector<int>dis(N, MOD);
		Calculate_Depth(edge, dis, sa);
		if (dis[sb] <= ja) {
			cout << "Alice" << endl;
			continue;
		}
		vector<int>depthA(N, MOD);
		Calculate_Depth(edge, depthA, 0);
		int rt = 0;
		for (int i = 1; i < N; i++) {
			if (depthA[i] > depthA[rt])rt = i;
		}
		vector<int>depthB(N, MOD);
		Calculate_Depth(edge, depthB, rt);
		if (*max_element(depthB.begin(), depthB.end()) > ja * 2) {
			cout << "Bob" << endl;
		}
		else {
			cout << "Alice" << endl;
		}
	}
}