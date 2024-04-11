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
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;
//const long long  int MOD = 998244353;
//long long int N, M, K, H, W, L, R;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<long long int>v(N);
	set<long long int>s;
	for (auto &i : v)cin >> i;
	for (auto i : v) {
		M = i - K;
		L = MOD * MOD;
		for (auto j : v) {
			L = min(L, abs(M - j));
		}
		if (L == K)s.insert(M);
		M = i + K;
		L = MOD * MOD;
		for (auto j : v) {
			L = min(L, abs(M - j));
		}
		if (L == K)s.insert(M);
	}
	cout << s.size() << endl;
	return 0;
}