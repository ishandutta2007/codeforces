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
//#include <atcoder/all>

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr long long int MOD = 998244353;
constexpr int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


void Solve() {
	cin >> N >> M;
	K = N + M;
	set<int>s;
	{
		for (int i = 0; i <= K / 2; i++) {
			int a = i, b = K / 2 - i;
			if (b <= M && a <= N && N - a <= (K + 1) / 2) {
				s.insert(i + (K + 1) / 2 - N + a);
			}
		}
	}
	{
		for (int i = 0; i <= (K + 1) / 2; i++) {
			int a = i, b = (K+1) / 2 - i;
			if (b <= M && a <= N && N - a <= (K + 0) / 2) {
				s.insert(i + (K + 0) / 2 - N + a);
			}
		}
	}
	cout << s.size() << endl;
	for (auto i : s)cout << i << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}