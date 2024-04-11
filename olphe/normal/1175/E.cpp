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
//const long long int MOD = 1000003;
//const int MOD = 998244353;
//const long long int MOD = 998244353;

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<vector<int>>tapi(500001, vector<int>(20, -1));
	for (int i = 0; i < N; i++) {
		cin >> L >> R;
		tapi[L][0] = max(tapi[L][0], R);
	}
	for (int i = 1; i <= 500000; i++) {
		tapi[i][0] = max(tapi[i][0], tapi[i - 1][0]);
		if (tapi[i][0] <= i)tapi[i][0] = -1;
	}
	for (int i = 1; i < 20; i++) {
		for (int j = 0; j <= 500000; j++) {
			if (tapi[j][i - 1] == -1)continue;
			tapi[j][i] = tapi[tapi[j][i-1]][i - 1];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> L >> R;
		int ans = 0;
		int cnt = L;
		for (int j = 19; j >= 0; j--) {
			if (tapi[cnt][j] == -1)continue;
			if (tapi[cnt][j] < R) {
				cnt = tapi[cnt][j];
				ans += (1 << j);
			}
		}
		if (tapi[cnt][0] >= R) {
			cout << ans + 1 << "\n";
		}
		else {
			cout << "-1\n";
		}
	}
}