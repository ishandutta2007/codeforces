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
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> H >> W >> K;
	vector<map<int, long long>>place(H);
	map<pair<int, int>, vector<pair<pair<int, int>,int>>>edge;
	vector<int>cost(H);
	for (int i = 0; i < H; i++) {
		cin >> cost[i];
	}
	for (int i = 0; i < K; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		a--, b--, c--, d--;
		place[a][b] = LLONG_MAX/10;
		place[c][d] = LLONG_MAX/10;
		edge[{a, b}].push_back({ { c,d },-e });
	}
	place[0][0] = 0;
	place[H - 1][W - 1] = LLONG_MAX/10;
	priority_queue<pair<long long,pair<int,int>>,vector<pair<long long, pair<int, int>>>,greater<pair<long long, pair<int, int>>>>PQ;
	for (int h = 0; h < H; h++) {
		for (auto i : place[h]) {
			PQ.push({ i.second,{h,i.first} });
		}
		while (!PQ.empty()) {
			long long dis;
			pair<int, int>p;
			int y, x;
			tie(dis, p) = PQ.top();
			tie(y, x) = p;
			PQ.pop();
			if (place[y][x] < dis)continue;
			for (auto i : edge[p]) {
				if (place[i.first.first][i.first.second] > dis + i.second) {
					place[i.first.first][i.first.second] = dis + i.second;
				}
			}
			auto it = place[y].find(x);
			if (it != place[y].begin()) {
				auto pv = prev(it);
				if (pv->second > dis + 1LL * cost[y] * (x - pv->first)) {
					pv->second = dis + 1LL * cost[y] * (x - pv->first);
					PQ.push({ pv->second, {y,pv->first} });
				}
			}
			auto nx = next(it);
			if (nx != place[y].end()) {
				if (nx->second > dis + 1LL * cost[y] * (nx->first - x)) {
					nx->second = dis + 1LL * cost[y] * (nx->first - x);
					PQ.push({ nx->second,{y,nx->first	} });
				}
			}
		}
	}
	if (place[H - 1][W - 1] > 1e17) {
		cout << "NO ESCAPE\n";
	}
	else {
		cout << place[H - 1][W - 1] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}