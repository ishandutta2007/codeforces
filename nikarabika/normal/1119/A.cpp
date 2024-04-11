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

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int le = 1;
	while (a[le] == a[le - 1]) le++;
	int ri = n - 2;
	while (a[ri] == a[ri + 1]) ri--;
	int ans = 0;
	for (int i = 0; i < n ; i++) {
		if (a[i] != a[0])
			smax(ans, i);
		else
			smax(ans, i - le);
		if (a[i] != a[n - 1])
			smax(ans, n - i - 1);
		else
			smax(ans, ri - i);
	}
	cout << ans << endl;
	return 0;
}