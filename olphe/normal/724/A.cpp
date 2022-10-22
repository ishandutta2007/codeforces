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

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<string>s({ "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" });
	string t, u;
	cin >> t >> u;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (s[i] == t && s[j] == u) {
				if (i == j)cout << "YES\n";
				else if ((i + 2) % 7 == j)cout << "YES\n";
				else if ((i + 3) % 7 == j)cout << "YES\n";
				else cout << "NO\n";
				return 0;
			}
		}
	}
}