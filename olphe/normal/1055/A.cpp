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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	K--;
	vector<int>v(N);
	vector<int>w(N);
	for (auto &i : v)cin >> i;
	for (auto &i : w)cin >> i;
	if (!v[0]) {
		cout << "NO\n";
		return 0;
	}
	if (v[K]) {
		cout << "YES\n";
		return 0;
	}
	for (int i = K + 1; i < N; i++) {
		if (v[i] && w[i] && w[K]) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}