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
const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<string>s(8);
	for (auto &i : s)cin >> i;
	int b = 0;
	int w = 7;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (s[i][j] == 'B') {
				bool flag = true;
				for (int k = i + 1; k < 8; k++) {
					if (s[k][j] != '.')flag = false;
				}
				if (flag)b = max(b, i);
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (s[i][j] == 'W') {
				bool flag = true;
				for (int k = i - 1; k >= 0; k--) {
					if (s[k][j] != '.')flag = false;
				}
				if (flag)w = min(w, i);
			}
		}
	}
	b = 7 - b;
	if (w <= b)cout<<"A\n";
	else cout << "B\n";
	return 0;
}