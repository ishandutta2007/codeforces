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

	cin >> N >> M;
	for (int i = M; i >N ; i--) {
		bool flag = true;
		for (int j = 2; j <= min((int)N, (int)sqrt(i)); j++) {
			if (i%j == 0) {
				flag = false;
			}
		}
		if (flag) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}