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

	cin >> L >> R >> K;
	cin >> N;
	vector<long long int>v(N);
	if (!N) {
		cout << L << endl;
		return 0;
	}
	for (auto &i : v)cin >> i;
	long long int ans = 0;
	long long int t = L;
	long long int box = L;
	if (v[0] > L) {
		cout << L << endl;
		return 0;
	}
	for (auto i : v) {
		if (t > box - i + 1 && box + K <= R) {
			ans = i - 1;
			t = box - i + 1;
		}
		box = max(i, box) + K;
	}
	if (box + K <= R)ans = box;
	cout << ans << endl;
	return 0;
}