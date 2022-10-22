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
#include "functional"
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

	cin >> N;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	int plus = 0, minus = 0;
	for (auto i : v) {
		if (i > 0 && i % 2 == 1)plus++;
		else if (i < 0 && abs(i) % 2 == 1)minus++;
	}
	auto w = v;
	for (auto &i : w)i /= 2;
	M = accumulate(w.begin(), w.end(),0LL);
	if (M < 0) {
		for (int i = 0; i < N; i++) {
			if (v[i]>0&&abs(v[i]) % 2 == 1&&M<0) {
				w[i]++;
				M++;
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			if (v[i]<0&&abs(v[i]) % 2 == 1&&M>0) {
				w[i]--;
				M--;
			}
		}
	}
	for (auto i : w)cout << i << endl;
}