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

//constexpr long long int MOD = 1000000007;
constexpr int MOD = 1000000007;
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
	vector<string>v(100);
	for (int i = 0; i < 100; i++) {
		v[i].resize(200,'0');
		v[i][i * 2] = '1';
		reverse(v[i].begin(), v[i].end());
	}
	string t(200, '0');
	for (int i = 0; i < s.size(); i++)t.pop_back();
	t += s;
	for (auto i : v)N += t > i;
	cout << N << endl;
}