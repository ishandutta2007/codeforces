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

	cin >> N;
	multiset<pair<int, string>>s;
	for (int i = 0; i < N; i++) {
		string t;
		cin >> t;
		s.insert({ t.size(),t });
	}
	string bef;
	for (auto i : s) {
		if (bef.empty()) {
			bef = i.second;
		}
		else {
			auto p = i.second.find(bef);
			if (p == string::npos) {
				cout << "NO\n";
				return 0;
			}
			bef = i.second;
		}
	}
	cout << "YES\n";
	for (auto i : s)cout << i.second << endl;
}