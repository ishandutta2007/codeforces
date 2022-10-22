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

	string s;
	cin >> s;
	bool flag = false;
	for (auto i : s) {
		if (flag) {
			if (i != 'a'&&i != 'i'&&i != 'u'&&i != 'e'&&i != 'o') {
				cout << "NO\n";
				return 0;
			}
			flag = false;
		}
		if (i != 'a'&&i != 'i'&&i != 'u'&&i != 'e'&&i != 'o'&&i != 'n')flag = true;
	}
	if (flag)cout << "NO\n";
	else cout << "YES\n";
	return 0;
}