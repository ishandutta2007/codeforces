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

	cin >> N;
	for (int i = N + 1; i <= 12345; i++) {
		set<int>s;
		int cnt = 0;
		int box = i;
		while (box) {
			s.insert(box % 10);
			cnt++;
			box /= 10;
		}
		if (cnt == s.size()) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}