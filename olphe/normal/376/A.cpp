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
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int p = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '^')p = i;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0'&&s[i] <= '9') {
			L += (i - p)*(s[i] - '0');
		}
	}
	if (L < 0)cout << "left" << endl;
	else if (L == 0)cout << "balance" << endl;
	else cout << "right" << endl;
}