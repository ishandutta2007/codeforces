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

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		vector<int>v(N);
		bool flag = true;
		int f = 0, s = 0;
		for (int i = 0; i < N; i++) {
			cin >> v[i];
			if (v[i] == 1)f = i;
			if (v[i] == N)s = i;
		}
		if (v.back() < v.front())flag = false;
		/*
		if (f < s&&f != 0 && s != N - 1) {
			int l = 0;
			int r=
		}
		reverse(v.begin(), v.end());
		int mx = 0;
		for (int i = 0; i < N; i++) {
			mx = max(mx, v[i]);
			if (mx != N && i + 1 == mx) {
				flag = false;
			}
		}
		*/
		if (flag)cout << "YES\n";
		else cout << "NO\n";
	}

}