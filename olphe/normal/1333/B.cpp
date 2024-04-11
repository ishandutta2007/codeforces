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
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		vector<int>v(N);
		for (auto &i : v)cin >> i;
		vector<int>w(N);
		for (auto &i : w)cin >> i;
		int a = 0, b = 0;
		bool flag = true;
		for (int i = 0; i < N; i++) {
			if (v[i] > w[i] && !a)flag = false;
			if (v[i] < w[i] && !b)flag = false;
			if (v[i] == -1)a = 1;
			else if (v[i] == 1)b = 1;
		}
		if (flag)cout << "YES\n";
		else cout << "NO\n";
	}
}