#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

vector<int> A = { 100, 20, 10, 5, 1 };

int n, c = 0;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (const auto &i : A) {
		c += (n / i);
		n %= i;
	}
	cout << c << '\n';
}