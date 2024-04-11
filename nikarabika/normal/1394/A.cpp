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
    LL n, d, m;
    cin >> n >> d >> m;
    LL a[n];
    LL sum[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    sum[0] = 0;
    for (int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + a[i];

    LL mid = upper_bound(a, a + n, m) - a;
    LL ans = 0;
    for (int i = n; i >= mid; i--) {
        LL burn = max(0LL, (n - i - 1) * d);
        LL ready = i;
        if (burn > ready)
            continue;
        LL burn1 = max(0LL, burn - (i - mid));
        smax(ans, sum[mid] - sum[burn1] + sum[n] - sum[i]);
    }
    cout << ans << endl;
	return 0;
}