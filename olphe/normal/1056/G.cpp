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
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	long long int ans;
	cin >> ans >> K;
	vector<long long int>used(N, -1);
	ans--;
	while (K > 0 && K%N != N - 1) {
		if (ans < M)ans += K % N;
		else ans -= K % N;
		ans += N;
		ans %= N;
		K--;
	}
	if (!K) {
		cout << ans + 1 << endl;
		return 0;
	}
	while (K > 0) {
		if (ans < M)ans += K % N;
		else ans -= K % N;
		ans += N;
		ans %= N;
		if (K%N == 0) {
			//cout << K << " " << ans << endl;
			if (used[ans] == -1)used[ans] = K / N;
			else {
				long long int box = used[ans] - K / N;
				ans = 0;
				for (int i = 0; i < N; i++) {
					if (used[i] != -1 && used[i] % box == 0) {
						if (used[ans]==-1||used[ans] % box) {
							ans = i;
						}
						if (used[ans] > used[i])ans = i;
					}
				}
				cout << ans + 1 << endl;
				return 0;
			}
		}
		K--;
		//	cout << K << endl;
	}
	cout << ans + 1 << endl;
}