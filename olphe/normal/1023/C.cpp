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

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	string s;
	cin >> s;
	L = M / 2;
	R = M / 2;
	for (auto i : s) {
		if (i == '('&&L) {
			cout << i;
			L--;
		}
		if (i == ')'&&R) {
			cout << i;
			R--;
		}
	}
	cout << endl;
	return 0;
}