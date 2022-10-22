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

//constexpr long long int MOD = 1000000007;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	int b = -1;
	int a = 0;
	for (auto i : s) {
		if (i == 'B') {
			b = max(b, 0);
			b++;
		}
		else {
			a++;
			if (b == -1) {
				cout << "No\n";
				return;
			}
			else if(b){
				b--;
			}
		}
	}
	if (b)cout << "No\n";
	else cout << "Yes\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}