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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<long long int>two(40);
	two[1] = 1;
	for (int i = 2; i < 40; i++) {
		two[i] = two[i - 1] * 2 + 1;
	}
	L = 1;
	vector<long long int>ans;
	while (N) {
		for (int i = 39; i > 0; i--) {
			if (two[i] <= N) {
				N -= two[i];
				for (int j = 0; j < i; j++) {
					ans.push_back(L);
				}
				break;
			}
		}
		L += K * 2;
	}
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}