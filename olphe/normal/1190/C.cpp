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

//const long long int MOD = 1000000007;
const int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;
const double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	string s;
	cin >> s;
	vector<int>v(1);
	for (auto i : s)v.push_back(i - '0');
	for (int i = 1; i <= N; i++)v[i] += v[i - 1];
	for (int i = 1; i + K - 1 <= N; i++) {
		int num = v[i - 1] + v[N] - v[i + K - 1];
		if (!num || num + K == N) {
			cout << "tokitsukaze" << endl;
			return 0;
		}
	}
	for (int i = 1; i + K - 1 <= N; i++) {
		int bef = v[i - 1];
		int aft = v[N] - v[i + K - 1];
		{
			if (bef < i - 1 && aft < N - (i + K)) {
				cout << "once again" << endl;
				return 0;
			}
			if (i - K >= 1 && v[i - K - 1] < i - K - 1) {
				cout << "once again" << endl;
				return 0;
			}
			if (i + K - 1 + K <= N && v[N] - v[i + K - 1 + K] < N - (i + K - 1 + K)) {
				cout << "once again" << endl;
				return 0;
			}
		}
		{
			if (bef&&aft) {
				cout << "once again" << endl;
				return 0;
			}
			if (i - K >= 1 && v[i - K - 1]) {
				cout << "once again" << endl;
				return 0;
			}
			if (i + K - 1 + K <= N && v[N] - v[i + K - 1 + K] ) {
				cout << "once again" << endl;
				return 0;
			}
		}
	}
	cout << "quailty\n";
}