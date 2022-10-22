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
const long double EPS = 1e-8;

long long int N, M, K, H, W, L, R, V, E;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	string s;
	cin >> s;
	s.push_back('1');
	bool flag = true;
	bool zero = false;
	long long int num = 0;
	for (auto i : s) {
		if (i == '0') {
			if (flag)num++;
			flag = false;
			zero = true;
		}
		else {
			flag = true;
		}
	}
	cout << max((long long int)0, num - 1) * min(M, K) + (K*zero) << endl;
	return 0;
}