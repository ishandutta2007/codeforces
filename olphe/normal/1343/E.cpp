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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N >> M;
		long long int ans = MOD * MOD;
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--, c--;
		vector<long long int>p(M);
		for (auto &i : p)cin >> i;
		p.push_back(0);
		sort(p.begin(), p.end());
		for (int i = 1; i <= M; i++) {
			p[i] += p[i - 1];
		}
		vector<vector<int>>edge(N);
		for (int i = 0; i < M; i++) {
			cin >> L >> R;
			L--, R--;
			edge[L].push_back(R);
			edge[R].push_back(L);
		}
		vector<int>adis(N, MOD);
		vector<int>bdis(N, MOD);
		vector<int>cdis(N, MOD);
		Calculate_Depth(edge, adis, a);
		Calculate_Depth(edge, bdis, b);
		Calculate_Depth(edge, cdis, c);
		for (int i = 0; i < N; i++) {
			int one = adis[i] + cdis[i];
			int two = bdis[i];
			if (one + two > M)continue;
			ans = min(ans, p[two] +p[two + one]);
		}
		cout << ans << endl;
	}
}