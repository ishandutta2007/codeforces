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
	int a[n],
	even[n + 1],
	odd[n + 1];
	even[0] = odd[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		even[i + 1] = even[i];
		odd[i + 1] = odd[i];
		if (i & 1)
			odd[i + 1] += a[i];
		else
			even[i + 1] += a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int e = even[i],
		o = odd[i];
		o += even[n] - even[i + 1];
		e += odd[n] - odd[i + 1];
		ans += e == o;
	}
	cout << ans << endl;
	return 0;
}