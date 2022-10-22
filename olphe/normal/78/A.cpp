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
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	string s, t, u;
	getline(cin, s);
	getline(cin, t);
	getline(cin, u);
	vector<int>v(256);
	v['a'] = v['i'] = v['u'] = v['e'] = v['o'] = 1;
	for (auto i : s)N += v[i];
	for (auto i : t)M += v[i];
	for (auto i : u)K += v[i];
	if (N == 5 && M == 7 && K == 5)cout << "YES\n";
	else cout << "NO\n";
}