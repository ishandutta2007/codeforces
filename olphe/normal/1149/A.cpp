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

using namespace std;

//const long long int MOD = 1000000007;
const int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	sort(v.begin(), v.end());
	if (v.front() == 2 || v.back() == 1) {
		for (auto i : v)cout << i << " ";
		cout << endl;
		return 0;
	}
	reverse(v.begin(), v.end());
	for (int i = 2; i < N; i++) {
		if (v[i] == 1) {
			swap(v[i], v[1]);
			break;
		}
	}
	for (auto i : v)cout << i << " ";
	cout << endl;
	return 0;
}