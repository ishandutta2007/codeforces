#include <iostream>

using namespace std;

#define M 998244353

typedef long long ll;

int n, m;

int main() {
	cin >> n >> m;
	ll u = 4;
	for (int i = 1; i <= n-1+m-1; i++) {
		u *= 2;
		u %= M;
	}
	cout << u << "\n";
}