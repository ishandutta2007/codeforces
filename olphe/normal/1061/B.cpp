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

	cin >> N >> M;
	vector<long long int>v(N);
	for (auto &i : v) {
		cin >> i;
		K = max(K, i);
	}
	sort(v.begin(), v.end());
	int add = 0;
	for (int i = 0; i < N; i++) {
		if (i + 1 - add > v[i])add++;
	}
	cout << accumulate(v.begin(), v.end(), 0LL) - K - add << endl;
}