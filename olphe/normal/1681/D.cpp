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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> K;
	long long goal = 1;
	N--;
	while (N--) {
		goal *= 10;
	}
	set<long long>s;
	s.insert(K);
	for (int loop = 1; loop <= 60; loop++) {
		set<long long>nx;
		for (auto i : s) {
			auto j = i;
			while (j) {
				if (j % 10 < 2) {
					j /= 10;
					continue;
				}
				if (goal * 2 / (j % 10) < i) {
					cout << loop << endl;
					return;
				}
				if (i * (j%10) >= goal) {
					cout << loop << endl;
					return;
				}
				nx.insert(i * (j%10));
				j /= 10;
			}
		}
		s = nx;
	}
	cout << -1 << endl;
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