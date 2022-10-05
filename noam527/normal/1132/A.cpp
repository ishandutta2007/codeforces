#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 9e18;
const int OO = 1;
using namespace std;

int a[4];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for (int i = 0; i < 4; i++) cin >> a[i];
	if (a[0] != a[3]) finish(0);
	if (a[0] == 0 && a[2] > 0) finish(0);
	finish(1);
}