#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 312345;

int cnt_true(ll x) {
    int ret = 0;
    while (x) {
        ret += x & 1;
        x >>= 1;
    }
    return ret;
}

ll a[maxn];
int cnt[maxn];
int n;

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%lld", &a[i]);
        a[i] = a[i - 1] + cnt_true(a[i]);
        cnt[i] = cnt[i - 1] + ((a[i] & 1) ^ 1);
    }
    ll ans = 0;
    FOR(i, 1, n) {
        if (i + 65 <= n) {
            if (a[i - 1] & 1)
                ans += n - i - 64 - cnt[n] + cnt[i + 64];
            else
                ans += cnt[n] - cnt[i + 64];
        }
        int s = 0, mmax = 0;
        FOR(j, i, min(i + 64, n)) {
            s = a[j] - a[i - 1];
            mmax = max(mmax, int(a[j] - a[j - 1]));
            if (s & 1) continue;
            if (mmax <= s - mmax) ans++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}