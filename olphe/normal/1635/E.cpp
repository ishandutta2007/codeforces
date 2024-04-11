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
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> M;
	vector<vector<pair<int,int>>>edge(N);
	for (int i = 0; i < M; i++) {
		cin >> K >> L >> R;
		L--, R--;
		edge[L].push_back({ K,R });
		edge[R].push_back({ K,L });
	}
	vector<int>dis(N, MOD);
	for (int i = 0; i < N; i++) {
		if (dis[i] != MOD)continue;
		queue<int>Q;
		Q.push(i);
		dis[i] = 0;
		while (!Q.empty()) {
			int cn = Q.front();
			Q.pop();
			for (auto i : edge[cn]) {
				if (dis[i.second] > dis[cn] + 1) {
					dis[i.second] = dis[cn] + 1;
					Q.push(i.second);
				}
				if (abs(dis[i.second] - dis[cn]) != 1) {
					cout << "NO" << endl;
					return;
				}
			}
		}
	}
	vector<vector<int>>e(N);
	vector<int>in(N);
	for (int i = 0; i < N; i++) {
		for (auto j : edge[i]) {
			if (j.second < i)continue;
			if (dis[i] & 1) {
				if (j.first == 1) {
					e[j.second].push_back(i);
					in[i]++;
				}
				else {
					e[i].push_back(j.second);
					in[j.second]++;
				}
			}
			else {
				if (j.first == 1) {
					e[i].push_back(j.second);
					in[j.second]++;
				}
				else {
					e[j.second].push_back(i);
					in[i]++;
				}
			}
		}
	}
	queue<int>Q;
	int sz = N;
	vector<int>p(N);
	for (int i = 0; i < N; i++) {
		if (in[i] == 0) {
			Q.push(i);
		}
	}
	int cnt = 0;
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		p[cn] = cnt++;
		for (auto i : e[cn]) {
			in[i]--;
			if (in[i] == 0)Q.push(i);
		}
		sz--;
	}
	if (sz) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (int i = 0; i < N; i++) {
		if (dis[i] & 1)cout << "R";
		else cout << "L";
		cout << " " << p[i] << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}