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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x, y;
	cin >> x >> y;
	int xx, yy;
	cin >> xx >> yy;
	int k;
	cin >> k;
	int mx = x * (xx - 1) + y * (yy - 1);
	cout << max(0, k - mx) << ' ';
	if (xx > yy)
		swap(x, y), swap(xx, yy);
	int ans = min(x, k / xx);
	k -= xx * ans;
	ans += min(y, k / yy);
	cout << ans << endl;
	return 0;
}