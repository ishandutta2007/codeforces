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

const long long int MOD = 1000000007;
//const int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;




int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	vector<int>w;
	for (int i = 0; i < N; i++) {
		w.push_back(v[i]);
		sort(w.begin(), w.end());
		long long int sum = 0;
		if (w.size() & 1) {
			for (int j = 0; j < w.size(); j += 2)sum += w[j];
		}
		else {
			for (int j = 1; j < w.size(); j += 2)sum += w[j];
		}
		if (sum > K) {
			cout << i << endl;
			return 0;
		}
	}
	cout << N << endl;
	return 0;
}