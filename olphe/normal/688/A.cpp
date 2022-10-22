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

	cin >> N >> K;
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < K; i++) {
		string s;
		cin >> s;
		cnt++;
		int box = 0;
		for (auto j : s) {
			if (j == '1') {
				box++;
			}
		}
		if (box == N)cnt = 0;
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}