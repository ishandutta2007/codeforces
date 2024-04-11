//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int solve() {
    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b * c)
        return cout << -1 << '\n', 0;
    LL k = min(a / (b * d), c / d);
    LL D = b * (c + c - k * d) * (k + 1) / 2;
    LL val = (k + 1) * (a - b * c);
    cout << max(a, val + D) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}