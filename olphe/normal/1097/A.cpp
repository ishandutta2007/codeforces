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

	string s;
	cin >> s;
	for (int i = 0; i < 5; i++) {
		string t;
		cin >> t;
		if (s[0] == t[0] || s[1] == t[1]) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}