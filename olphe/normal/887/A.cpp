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
#include "iomanip"
#include "cmath"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	bool flag = false;
	for (auto i : s) {
		if (i == '1') {
			flag = true;
		}
		if (flag&&i == '0') {
			N++;
		}
	}
	if (N >= 6) {
		cout << "yes\n";
	}
	else {
		cout << "no\n";
	}
	return 0;
}