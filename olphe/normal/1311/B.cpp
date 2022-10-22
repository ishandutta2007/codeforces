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
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-12;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N >> M;
		vector<int>v(N);
		vector<int>w(M);
		for (auto &i : v)cin >> i;
		for (auto &i : w)cin >> i;
		auto u = v;
		sort(u.begin(), u.end());
		sort(w.begin(), w.end());
		int st = -1;
		int ed = -1;
		for (auto i : w) {
			if (st == -1) {
				st = i;
				ed = i;
			}
			else if (ed + 1 == i) {
				ed++;
			}
			else {
				sort(v.begin() + st - 1, v.begin() + ed + 1);
				st = i, ed = i;
			}
		}
		if (st != -1) {
			sort(v.begin() + st - 1, v.begin() + ed + 1);
		}
		if (u == v)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}