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

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	while (N--) {
		cin >> M;
		vector<int>v(M);
		for (auto& i : v)cin >> i;
		auto sum = accumulate(v.begin(), v.end(), 0);
		bool o = false, e = false;
		for (auto i : v) {
			if (i & 1)o = true;
			else e = true;
		}
		if (sum % 2 == 1 || (o && e))cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}