#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 0;
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	if (m == 0) finish(1);
	if (m == n) finish(0);
	finish(min(m, n - m));
}