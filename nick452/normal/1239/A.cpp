#include <bits/stdc++.h>

using namespace std;

const int kModular = 1000000007;

int fib(int n) {
	int a0 = 1;
	int a1 = 1;
	for (int i = 2; i <= n; ++i) {
		int a2 = (a0 + a1) % kModular;
		a0 = a1;
		a1 = a2;
	}
	return a1;
}
int main() {
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int results = (fib(n) + fib(m)) % kModular;
	results = (results + kModular - 1) % kModular;
	results = (results * 2) % kModular;
	printf("%d\n", results);
	return 0;
}