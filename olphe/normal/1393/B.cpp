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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>num(100001);
	vector<int>sum(100001);
	for (int i = 0; i < N; i++) {
		cin >> M;
		num[M]++;
		sum[num[M]]++;
	}
	cin >> M;
	while (M--) {
		char a;
		cin >> a >> K;
		if (a == '+') {
			num[K]++;
			sum[num[K]]++;
		}
		else {
			sum[num[K]]--;
			num[K]--;
		}
		if (sum[8]) {
			cout << "YES\n";
		}
		else if (sum[6]  && sum[2]>=2) {
			cout << "YES\n";
		}
		else if (sum[4] >= 2) {
			cout << "YES\n";
		}
		else if (sum[4] >= 1 && sum[2] >= 3) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
}