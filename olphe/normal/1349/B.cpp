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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> M;
	while (M--) {
		cin >> N >> K;
		vector<int>v(N);
		bool flag = false;
		vector<int>p;
		for (auto &i : v) {
			cin >> i;
			if (i == K)flag = true;
			if (i >= K)i = 1;
			else i = 0;
		}
		if (!flag) {
			cout << "no\n";
			continue;
		}
		if (N == 1) {
			if (v[0])cout << "yes\n";
			else cout << "no\n";
			continue;
		}
		for (int i = 0; i < N; i++) {
			if (v[i] == 1)p.push_back(i);
		}
		flag = false;
		for (int i = 1; i < p.size(); i++) {
			flag |= (p[i] - p[i - 1]) <= 2;
		}
		if (flag)cout << "yes\n";
		else cout << "no\n";
	}
};