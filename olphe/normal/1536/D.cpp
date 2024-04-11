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
	cin >> N;
	set<int>st;
	int num = -1;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	for (auto i : v){
		M = i;
		if (st.empty()) {
			st.insert(M);
			num = M;
		}
		else {
			auto it = st.find(num);
			if (*it == M) {
				continue;
			}
			if (*it < M) {
				if (next(it) != st.end() && *next(it) < M) {
					cout << "NO\n";
					return;
				}
				st.insert(M);
			}
			else if (*it > M) {
				if (it != st.begin() && *prev(it) > M) {
					cout << "NO\n";
					return;
				}
				st.insert(M);
			}
		}
		num = M;
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}