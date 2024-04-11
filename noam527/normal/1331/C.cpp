#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 2147483647;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

// And after happily lived ever they

int a[6] = { 0,5,3,2,4,1 };

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, x = 0;
	cin >> n;
	for (int i = 0; i < 6; i++) {
		if (n & (1 << i))
			x |= (1 << (5 - a[5 - i]));
	}
	cout << x << endl;
}