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
	for (int i = 0; i < N; i++) {
		string s, t;
		cin >> s >> t;
		sort(s.begin(), s.end());
		bool flag = false;
		for (int j = 0; j <= (int)(t.size()) - (int)(s.size()); j++) {
			string u;
			for (int k = 0; k < s.size(); k++) {
				u.push_back(t[j + k]);
			}
			sort(u.begin(), u.end());
			if (s == u) {
				flag = true;
			}
		}
		if (flag)cout << "YES\n";
		else cout << "NO\n";
	}
}