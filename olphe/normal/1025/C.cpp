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
	N = s.size();
	s += s;
	int num = 1;
	char bef = s[0];
	int ans = 1;
	for (int i = 1; i < N * 2; i++) {
		if (s[i] != bef) {
			num++;
			bef = s[i];
			ans = max(ans, num);
		}
		else {
			num = 1;
		}
	}
	cout << min(ans, (int)N) << endl;


	return 0;
}