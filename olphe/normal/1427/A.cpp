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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		vector<int>v(N);
		for (auto &i : v)cin >> i;
		sort(v.begin(), v.end());
		if (accumulate(v.begin(), v.end(), 0LL) > 0)reverse(v.begin(), v.end());
		if (accumulate(v.begin(), v.end(),0LL) == 0)cout << "NO\n";
		else {
			cout << "YES\n";
			for (auto i : v)cout << i << " ";
			cout << endl;
		}
	}
}