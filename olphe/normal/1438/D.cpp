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
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	vector<int>cnt(30);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 30; j++) {
			cnt[j] += v[i] >> j & 1;
		}
	}
	for (int i = 0; i < 30; i++) {
		if ((N - cnt[i]) % 2 && cnt[i] % 2) {
			cout << "NO\n";
			return 0;
		}
	}
	vector<int>a;
	vector<int>b;
	vector<int>c;
	for (int i = 0; i + 2 < N; i += 2) {
		a.push_back(i);
		b.push_back(i + 1);
		c.push_back(i + 2);
	}
	for (int i = 0; i + 2 < N; i += 2) {
		a.push_back(i);
		b.push_back(i + 1);
		if (N & 1)c.push_back(N - 1);
		else c.push_back(N - 2);
	}
	if (a.size() > N) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	cout << a.size() << endl;
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] + 1 << " " << b[i] + 1 << " " << c[i] + 1 << "\n";
	}
}