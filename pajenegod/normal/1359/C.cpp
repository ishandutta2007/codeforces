// Not my code https://codeforces.com/blog/entry/100106

// #pragma GCC target("fpmath=sse,sse2") // Turns off excess precision
#pragma GCC target("fpmath=387") // Turns on excess precision


#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>  using oset =
    tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;
#define odrkey order_of_key
#define fbodr find_by_order
#define ll long long
#define sq(a) ((a)*(a))
#define ull unsigned long long
#define all(x) (x).begin(),(x).end()
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sz 100009
#define pi 3.1415926536
#define nwl cout << "\n"
ll Pow(ll a, ll b) {
	ll ans = 1;
	for (int i = 0; i < b; i++) {
		ans *= a;
	}
	return ans;
}
ll lcm(ll a, ll b) {
	return (a * b) / __gcd(a, b);
}
double fun(double a, double b, double i) {
	double tm = (a * (i + 1)) + (b * (i));
	tm /= (2 * i + 1);
	return tm;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (2 * c <= (a + b)) {
			cout << "2\n";
		}
		else {
			ll up = (a - c);
			ll down = (2 * c - a - b);
			ll x = up / down;
			ll y = x + 1;
			double tm2 = abs(c - fun(a, b, y));
			double tm1 = abs(c - fun(a, b, x));
			if (tm1 <= tm2 || (tm2 - tm1) >= 0.000000001) {
				cout << 2 * x + 1 << '\n';
			}
			else {
				cout << 2 * y + 1 << "\n";
			}
		}
	}
}