#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long 
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int lcm(int a, int b) {
	return ((a * b) / (__gcd(a, b)));
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int p; cin >> p;
	int q; cin >> q;
	int a; cin >> a;
	int b; cin >> b;
	int dpq = n / lcm(p, q);
	int dp = n / p - dpq;
	int dq = n / q - dpq;
	int r = dp * a + dq * b + dpq * max(a, b);
	cout << r;
}