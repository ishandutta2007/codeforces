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
	int n;
	cin >> n;
	int a[n + 10];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[0] = 0;
	a[n + 1] = 1001;
	n += 2;
	int ans = 0,
		mx = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1] + 1)
			mx++;
		else
			mx = 0;
		smax(ans, mx - 1);
	}
	cout << ans << endl;
	return 0;
}