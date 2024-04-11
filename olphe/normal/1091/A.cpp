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
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int>v(3);
	for (int i = 0; i < 3; i++)cin >> v[i];
	int ans = 1000000;
	for (int i = 0; i < 3; i++) {
		v[i] -= i + 1;
		ans = min(ans, v[i]);
	}
	cout << ans * 3 + 6 << endl;
	return 0;
}