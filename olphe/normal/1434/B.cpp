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

	cin >> N;
	M = N * 2;
	vector<int>ans;
	vector<int>v(M);
	while (M--) {
		char c;
		cin >> c;
		if (c == '+') {

		}
		else {
			cin >> v[M];

		}
	}
	set<int>s;
	for (auto i : v) {
		if (i == 0) {
			if (s.empty()) {
				cout << "NO\n";
				return 0;
			}
			ans.push_back(*s.begin());
			s.erase(s.begin());
		}
		else {
			if (!s.empty()&&*s.begin() < i) {
				cout << "NO\n";
				return 0;
			}
			s.insert(i);
		}
	}
	cout << "YES\n";
	reverse(ans.begin(), ans.end());
	for (auto i : ans)cout << i << " ";
	cout << endl;
}