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

const int maxl = 25;
int cnt[1 << maxl],
    sum[(1 << maxl) + 10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    LL n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    LL ans = 0;
    for (int i = 0; i < maxl; i++) {
        memset(cnt, 0, sizeof cnt);
        LL c[2] = {0LL};
        for (int j = 0; j < n; j++) {
            cnt[a[j] & ((1 << i) - 1)]++;
            c[(a[j] >> i) & 1]++;
        }
        for (int j = 0; j < (1 << i); j++)
            sum[j + 1] = sum[j] + cnt[j];
        LL coming = 0;
        for (int j = 0; j < (1 << i); j++) {
            coming += 1LL * cnt[j] * (n - sum[(1 << i) - j]);
            if (j >= (1 << (i)) / 2)
                coming -= cnt[j];
        }
        if (i == 0)
            coming = 0;
        coming /= 2;
        LL cur = c[0] * c[1];
        cur += coming;
        ans += (cur & 1LL) << i;
    }
    cout << ans << '\n';
	return 0;
}