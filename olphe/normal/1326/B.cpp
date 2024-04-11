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
constexpr long double EPS = 1e-8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	vector<int>w(N);
	int m = v[0];
	w[0] = v[0];
	for (int i = 1; i < N; i++) {
		w[i] = m + v[i];
		m = max(m, w[i]);
	}
	for (auto i : w)cout << i << " ";
	cout << endl;
}