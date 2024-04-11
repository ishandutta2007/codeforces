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

//const long long int MOD = 1000000007;
const long long  int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<string> s(N);
	for (auto &i : s)cin >> i;
	bool flag = false;
	for (auto &i : s) {
		if (i[0] == i[1] && i[0] == 'O') {
			i[0] = i[1] = '+';
			flag = true;
			break;
		}
		if (i[4] == i[3] && i[4] == 'O') {
			i[3] = i[4] = '+';
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << "YES\n";
		for (auto i : s)cout << i << endl;
	}
	else {
		cout << "NO\n";
	}
	return 0;
}