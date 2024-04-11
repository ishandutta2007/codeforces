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
//const long long int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	L = -1, R = M;
	while (R - L > 1) {
		int mid = (R + L) / 2;
		int bef = -1;
		for (int i = 0; i < N; i++) {
			int box = v[i] + mid;
			if (box >= M) {
				box %= M;
				if (box < bef)bef = max(bef,v[i]);
			}
			else {
				if (box < bef) {
					bef = MOD;
				}
				if (v[i] > bef)bef = v[i];
			}
		}
		if (bef != MOD)R = mid;
		else L = mid;
	}
	cout << R << endl;
}