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
#include "functional"

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

	string s;
	cin >> s;
	vector<long long int>v(s.size());
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1] && s[i] == 'v') {
			v[i]++;
		}
		v[i] += v[i - 1];
	}
	long long int ans = 0;
	for (int i = 2; i < s.size(); i++) {
		if (i + 2 >= s.size())break;
		if (s[i] == 'o') {
			ans += v[i] * (v.back() - v[i]);
		}
	}
	cout << ans << endl;
}