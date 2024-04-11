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

unsigned long long int func(long long int a, long long int b, long long int c) {
	unsigned long long int ret = 0;
	if (a > b) {
		ret += (a - b)*(a - b);
	}
	else {
		ret += (b - a)*(b - a);
	}
	if (c > b) {
		ret += (c - b)*(c - b);
	}
	else {
		ret += (b - c)*(b - c);
	}
	if (a > c) {
		ret += (a - c)*(a - c);
	}
	else {
		ret += (c - a)*(c - a);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> R;
	while (R--) {
		cin >> N >> M >> K;
		set<long long int>a;
		set<long long int>b;
		set<long long int>c;
		for (int i = 0; i < N; i++) {
			cin >> L;
			a.insert(L);
		}
		for (int i = 0; i < M; i++) {
			cin >> L;
			b.insert(L);
		}
		for (int i = 0; i < K; i++) {
			cin >> L;
			c.insert(L);
		}
		a.insert(-MOD);
		b.insert(-MOD);
		c.insert(-MOD);
		a.insert(MOD * 2);
		b.insert(MOD * 2);
		c.insert(MOD * 2);
		unsigned long long int ans = ULLONG_MAX;
		for (auto i : a) {
			if (i<0 || i>MOD)continue;
			auto itb = b.lower_bound(i);
			auto itc = prev(c.upper_bound(i));
			ans = min(ans, func(i, *itb, *itc));
			itb = prev(b.upper_bound(i));
			itc = c.lower_bound(i);
			ans = min(ans, func(i, *itb, *itc));
		}
		for (auto i : b) {
			if (i<0 || i>MOD)continue;
			auto itb = a.lower_bound(i);
			auto itc = prev(c.upper_bound(i));
			ans = min(ans, func(i, *itb, *itc));
			itb = prev(a.upper_bound(i));
			itc = c.lower_bound(i);
			ans = min(ans, func(i, *itb, *itc));
		}
		for (auto i : c) {
			if (i<0 || i>MOD)continue;
			auto itb = a.lower_bound(i);
			auto itc = prev(b.upper_bound(i));
			ans = min(ans, func(i, *itb, *itc));
			itb = prev(a.upper_bound(i));
			itc = b.lower_bound(i);
			ans = min(ans, func(i, *itb, *itc));
		}
		cout << ans << endl;
	}
}