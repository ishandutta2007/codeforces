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


void Solve() {
	cin >> N >> M;
	vector<vector<pair<int, int>>>edge(N);
	vector<int>dis(N, MOD);
	vector<vector<int>>e(N);
	for (int i = 0; i < M; i++) {
		cin >> L >> R >> K;
		L--, R--;
		e[L].push_back(R);
		e[R].push_back(L);
		edge[L].push_back({ R,K });
		edge[R].push_back({ L,-K });
	}
	dis[0] = 0;
	queue<int>QQ;
	QQ.push(0);
	while (!QQ.empty()) {
		int cn = QQ.front();
		QQ.pop();
		for (auto i : e[cn]) {
			if (dis[i] > dis[cn] + 1) {
				dis[i] = dis[cn] + 1;
				QQ.push(i);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (auto j : e[i]) {
			if (dis[i] % 2 == dis[j] % 2) {
				cout << "No\n";
				return;
			}
		}
	}
	int score = -1;
	vector<int>ans;
	for (int i = 0; i < N; i++) {
		vector<int>l(N, -MOD);
		vector<int>r(N, MOD);
		l[i] = r[i] = 50000;
		queue<int>Q;
		vector<int>dif(N, MOD * 2);
		Q.push(i);
		while (!Q.empty()) {
			int cn = Q.front();
			Q.pop();
			if (r[cn] % 2 != l[cn] % 2)break;
			if (r[cn] < l[cn]) {
				r[cn] = l[cn] + 1;
				break;
			}
			if (r[cn] - l[cn] == dif[cn])continue;
			dif[cn] = r[cn] - l[cn];
			for (auto j : edge[cn]) {
				if (j.second == 0) {
					if (l[j.first]<l[cn] - 1 || r[j.first]>r[cn] + 1) {
						l[j.first] = max(l[j.first], l[cn] - 1);
						r[j.first] = min(r[j.first], r[cn] + 1);
						Q.push(j.first);
					}
				}
				else {
					if (l[j.first]<l[cn] + j.second || r[j.first]>r[cn] + j.second) {
						l[j.first] = max(l[j.first], l[cn] + j.second);
						r[j.first] = min(r[j.first], r[cn] + j.second);
						Q.push(j.first);
					}
				}
			}
		}
		bool flag = true;
		for (int j = 0; j < N; j++) {
			if (l[j] % 2 != r[j] % 2)flag = false;
		}
		if (flag&&l[i] - *min_element(l.begin(), l.end()) > score) {
			score = l[i] - *min_element(l.begin(), l.end());
			ans = l;
		}
	}
	if (ans.empty()) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	cout << score << endl;
	for (auto i : ans)cout << i << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//cin >> T;
	T = 1;
	while (T--) {
		Solve();
	}
}