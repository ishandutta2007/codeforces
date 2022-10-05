#include <iostream>
#include <algorithm>
#include <vector>
#define done(X, Y) cout << (X) << " " << (Y) << endl; return 0
typedef long long ll;
using namespace std;

int main() {
	ll n, k, left, cx, cy = 0; cin >> n;
	k = ll((-3.0 + 2.0 * sqrt(3 * n + 2.25)) / 6.0) + 1;
	left = n - 3 * k * (k - 1);
	cx = 2 * (k - 1);
	if (left == 0) { done(cx, 0); }
	if (left == 1) { done(cx + 1, 2); }
	if (left <= k) { done(cx - left + 2, left * 2); }
	cx -= (k - 2), cy += k * 2, left -= k;
	if (left <= k) { done(cx - left * 2, cy); }
	cx -= k * 2, left -= k;
	if (left <= k) { done(cx - left, cy - left * 2); }
	cx -= k, cy -= k * 2, left -= k;
	if (left <= k) { done(cx + left, cy - left * 2); }
	cx += k, cy -= k * 2, left -= k;
	if (left <= k) { done(cx + left * 2, cy); }
	cx += k * 2, left -= k;
	done(cx + left, cy + left * 2);
}