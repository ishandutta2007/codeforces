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
constexpr long double EPS = 1e-12;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int K;
	cin >> K;
	while (K--) {
		long long int N, M;
		cin >> N >> M;
		vector<long long int>v(N);
		for (auto &i : v)cin >> i;
		vector<int>num(60);
		for (auto i : v) {
			int cnt = 0;
			while (i) {
				num[cnt++] += i % M;
				i /= M;
			}
		}
		if (*max_element(num.begin(), num.end()) <= 1)cout << "YES\n";
		else cout << "NO\n";
	}
}