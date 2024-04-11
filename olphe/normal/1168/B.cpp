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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	N = s.size();
	long long int ans = N * (N + 1) / 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 8; j++) {
			int ed = i + j;
			if (ed >= N)break;
			bool flag = true;
			for (int k = 1; k <= 4; k++) {
				for (int l = i; l < N; l++) {
					if (l + 2 * k > ed)break;
					if (s[l] == s[l + k] && s[l] == s[l + 2 * k])flag = false;
				}
			}
			if (flag)ans--;
		}
	}
	cout << ans << endl;
}