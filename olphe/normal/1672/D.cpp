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
	cin >> N;
	vector<int>v(N);
	vector<int>w(N);
	for (auto& i : v)cin >> i;
	for (auto& i : w)cin >> i;
	multiset<int>ms;
	int bef = -1;
	int idx = 0;
	for (auto i : w) {
		if (i == v[idx]) {
			idx++;
		}
		else {
			if (i == bef && ms.find(bef) != ms.end()) {
				ms.erase(ms.find(bef));
			}
			else {
				while (idx < N && v[idx] != i) {
					ms.insert(v[idx]);
					idx++;
				}
				if (idx < N && i == v[idx]) {
					idx++;
				}
			}
		}
		bef = i;
	}
	if (ms.size())cout << "No\n";
	else cout<<"Yes\n";
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