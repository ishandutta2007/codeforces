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
	LL n, k;
	cin >> n >> k;
	LL a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	LL lo = 1,
	   hi = 1e10;
	while (hi - lo > 1) {
		LL mid = (lo + hi) >> 1;
		LL sum = 0;
		for (int i = n / 2; i < n; i++)
			sum += max(0LL, mid - a[i]);
		if (sum <= k)
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << endl;
	return 0;
}