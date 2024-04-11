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

	cin >> N >> M;
	vector<int>p(N + 1);
	vector<int>v(M);
	for (int i = 0; i < M; i++)cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < M; i++) {
		p[v[i]] = i;
	}
	cin >> L >> R;
	vector<vector<int>>dis(M, vector<int>(L, MOD));
	dis[0][0] = 0;
	deque<pair<int, int>>Q;
	Q.emplace_back(0, 0);
	while (!Q.empty()) {
		int cn, md;
		tie(cn, md) = Q.front();
		Q.pop_front();
		if (cn) {
			int nx = md + v[cn] - v[cn - 1];
			if (nx < L) {
				if (dis[cn - 1][nx] > dis[cn][md]) {
					dis[cn - 1][nx] = dis[cn][md];
					Q.emplace_front(cn - 1, nx);
				}
			}
			else if (nx == L) {
				if (dis[cn - 1][0] > dis[cn][md] + 1) {
					dis[cn - 1][0] = dis[cn][md] + 1;
					Q.emplace_back(cn - 1, 0);
				}
			}
		}
		if (cn + 1 < M) {
			int nx = md + v[cn + 1] - v[cn];
			if (nx < L) {
				if (dis[cn + 1][nx] > dis[cn][md]) {
					dis[cn + 1][nx] = dis[cn][md];
					Q.emplace_front(cn + 1, nx);
				}
			}
			else if (nx == L) {
				if (dis[cn + 1][0] > dis[cn][md] + 1) {
					dis[cn + 1][0] = dis[cn][md] + 1;
					Q.emplace_back(cn + 1, 0);
				}
			}
		}
	}
	long long int ans = MOD * MOD;
	for (int i = 0; i < L; i++) {
		if (dis.back()[i] == MOD)continue;
		if (i)ans = min(ans, 1LL * dis.back()[i] * (L + R) + i);
		else ans = min(ans, 1LL * dis.back()[i] * (L + R) - R);
	}
	if (ans == MOD * MOD)ans = -1;
	cout << ans << endl;
}