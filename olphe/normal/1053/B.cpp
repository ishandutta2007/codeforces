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

	cin >> N;
	vector<long long int>v(N+1);
	for (int i = 1; i <= N; i++)cin >> v[i];
	vector<int>num(N + 1);
	vector<int>sum(N + 1);
	for (int i = 1; i <= N; i++) {
		while (v[i]) {
			num[i] += v[i] & 1;
			v[i] >>= 1;
		}
	}
	long long int one = 0;
	long long int zero = 1;
	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + num[i];
		sum[i] &= 1;
		if (sum[i] & 1)one++;
		else zero++;
		//cout << i << " " << sum[i] << endl;
	}
//	cout << zero << " " << one << endl;
	long long int ans = 0;
	ans += zero * (zero - 1) / 2;
	ans += one * (one - 1) / 2;
	
	for (int i = 1; i <= N; i++) {
		int sb = num[i];
		int mb = num[i];
		if (mb * 2 > sb&&sb % 2 == 0)ans--;
		for (int j = 1; j <= 64; j++) {
			if (i + j > N)continue;
			sb += num[i + j];
			mb = max(mb, num[i + j]);
			if (mb * 2 > sb&&sb % 2 == 0)ans--;
		}
	}
	cout << ans << endl;
	return 0;
}