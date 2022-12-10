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

const int maxn = 1000 * 1000 + 10;
const LL INF = 2e18;
LL dp0[maxn],
   dp1[maxn],
   dp2[maxn],
   suf[maxn],
   a[maxn],
   n, r1, r2, r3, d, minr;

LL fight(LL x, int cnt) {
    if (cnt == 1)
        return x * r1 + r3;
    else
        return min(fight(x, 1), min(r2 + minr, r1 * (x + 1) + minr));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> r1 >> r2 >> r3 >> d;
    minr = min(min(r1, r2), r3);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    // init
    {
        dp0[0] = fight(a[0], 1);
        dp1[0] = fight(a[0], 2);
        dp2[0] = INF;
    }
    for (int i = 1; i < n; i++) {
        // dp0
        dp0[i] = fight(a[i], 1) + min(dp0[i - 1], dp2[i - 1]) + d;

        // dp1
        dp1[i] = fight(a[i], 2) + min(dp0[i - 1], dp2[i - 1]) + d;

        // dp2
        dp2[i] = fight(a[i], 2) + 3 * d + min(dp1[i - 1], dp2[i - 1]);
    }

    // unut
    {
        suf[n - 2] = min(fight(a[n - 1], 2) + 4 * d, fight(a[n - 1], 1) + 2 * d) + fight(a[n - 2], 2);
    }
    for (int i = n - 3; i >= 0; i--)
        suf[i] = suf[i + 1] + fight(a[i], 2) + 2 * d;

    LL ans = min(dp0[n - 1], min(dp2[n - 1], suf[0]));
    for (int i = 1; i < n - 1; i++)
        smin(ans, min(dp0[i - 1], dp2[i - 1]) + suf[i] + d);
    cout << ans << '\n';
	return 0;
}