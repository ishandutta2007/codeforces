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

const int maxn = 5e5 + 10;
LL a[maxn],
   dp[maxn],
   pd[maxn],
   n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	LL sum = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i], sum += a[i];
	sort(a, a + n);
	for (int i = 1; i < n; i++)
		dp[i] = dp[i - 1] + (a[i] - a[i - 1]) * i;
	for (int i = n - 2; i >= 0; i--)
		pd[i] = pd[i + 1] + (a[i + 1] - a[i]) * (n - i - 1);
	LL l = upper_bound(dp, dp + n, k) - dp - 1;
	LL r = n - 1;
	while (pd[r] <= k and r >= 0) r--;
	r++;
	LL lval = a[l] + (k - dp[l]) / (l + 1);
	LL rval = a[r] - (k - pd[r]) / (n - r);
	cout << max(LL(sum % n != 0), rval - lval) << endl;
	return 0;
}