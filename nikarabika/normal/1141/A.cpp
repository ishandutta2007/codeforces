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
	int n, m;
	cin >> n >> m;
	if (m % n) 
		return cout << -1 << endl, 0;
	int x = m / n;
	int ans = 0;
	while (x != 1) {
		if (x % 2 == 0)
			x /= 2, ans++;
		else if (x % 3 == 0)
			x /= 3,
			  ans++;
		else
			return cout << -1 << endl, 0;
	}
	cout << ans << endl;
	return 0;
}