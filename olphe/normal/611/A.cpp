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
	string s;
	cin >> s >> s;
	if (s[0] == 'w') {
		if (N == 5 || N == 6)cout << 53 << endl;
		else cout << 52 << endl;
	}
	else {
		if (N < 30)cout << 12 << endl;
		else if (N == 30)cout << 11 << endl;
		else cout << 7 << endl;
	}
	return 0;
}