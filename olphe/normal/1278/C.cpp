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

	cin >> K;
	while (K--) {
		cin >> N;
		N *= 2;
		vector<int>v(N);
		for (auto &i : v) {
			cin >> i;
		}
		vector<int>one(N + 2);
		vector<int>two(N + 2);
		for (int i = 0; i < N; i++) {
			if (v[i] == 1)one[i + 1]++;
			else two[i + 1]++;
		}
		for (int i = 1; i <= N / 2; i++) {
			one[i] += one[i - 1];
			two[i] += two[i - 1];
		}
		for (int i = N; i > N / 2; i--) {
			one[i] += one[i + 1];
			two[i] += two[i + 1];
		}
		map<int, int>a;
		map<int, int>b;
		for (int i = 0; i <= N / 2; i++) {
			a[one[i] - two[i]] = N / 2 - i;
		}
		for (int i = N + 1; i > N / 2; i--) {
			b[two[i] - one[i]] = i - N / 2 - 1;
		}
		int ans = N * 5;
		for (auto i : a) {
			if (b.find(i.first) == b.end())continue;
			ans = min(i.second + b[i.first], ans);
		}
		cout << ans << endl;
	}
	
}