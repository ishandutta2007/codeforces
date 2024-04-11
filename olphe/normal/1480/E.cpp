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

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


void Solve() {
	cin >> L >> R;
	N = 32;
	vector<int>l(N + 1);
	vector<int>r(N + 1);
	l[2] = r[2] = 1;
	for (int i = 3; i <= 21; i++) {
		l[i] = l[i - 1];
		r[i] = r[i - 1] * 2;
	}
	vector<vector<pair<int, int>>>edge(N + 1);
	for (int i = 1; i <= 21; i++) {
		for (int j = i + 1; j <= 21; j++) {
			edge[i].push_back({ j,max(1,r[i]) });
			M++;
		}
	}
	for (int i = 21; i >= 2; i--) {
		if (R - L >= r[i] - l[i] && R > r[i]) {
			edge[i].push_back({ 32,R - r[i] });
			M++;
			R -= max(1,r[i]);
		}
	}
	int cnt = 22;
	while (R >= L && R > 1) {
		edge[1].push_back({ cnt,R - 1 });
		edge[cnt++].push_back({ 32,1 });
		M++;
		M++;
		R--;
	}
	if (R >= L && R == 1) {
		edge[1].push_back({ 32,1 });
		M++;
	}
	cout << "YES\n";
	cout << N << " " << M << endl;
	for (int i = 1; i <= 32; i++) {
		for (auto j : edge[i]) {
			cout << i << " " << j.first << " " << j.second << endl;
		}
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