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

const long long  int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 2; i <= 1999; i++) {
		if (i & 1) {
			M = ((N - 1 + i) % i) + 1;
			long long int b = M * i;
			K = N - M;
			K /= i;
			b += K;
			if (b <= 1000000) {
				vector<int>ans(i + 1);
				for (int j = 1; j < i; j += 2) {
					ans[j] = M;
					ans[j + 1] = -M * 3;
				}
				ans[i] = i * M;
				ans[i] += K;
				cout << ans.size() << endl;
				for (auto j : ans) {
					cout << j << " ";
				}
				cout << endl;
				return 0;
			}
		}
		else {
			M = ((N - 1 + i) % i) + 1;
			long long int b = M * i;
			K = N - M;
			K /= i;
			b += K;
			if (b <= 1000000) {
				vector<int>ans(i + 1);
				ans[0] = M;
				ans[1] = -M * 2;
				for (int j = 2; j < i; j += 2) {
					ans[j] = M;
					ans[j + 1] = -M * 3;
				}
				ans[i] = i * M;
				ans[i] += K;
				cout << ans.size() << endl;
				for (auto j : ans) {
					cout << j << " ";
				}
				cout << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}