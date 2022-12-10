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

const int maxn = 1e6;
LL a[maxn],
   n, m;

LL best(LL d) {
	LL result = 0;
	for (int i = 0; i < n; i++)
		if (a[i] >= i / d)
			result += a[i] - i / d;
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n, greater<int>());
	int lo = 0,
		hi = n + 1;
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		if (best(mid) >= m)
			hi = mid;
		else
			lo = mid;
	}
	if (hi == n + 1)
		cout << -1 << endl;
	else
		cout << hi << endl;
	return 0;
}