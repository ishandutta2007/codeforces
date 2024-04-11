#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 1123456;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int n;
ll k, d, dp[12][1 << 12], to[1 << 12];
pair<ll, ll> judge[maxn];
vector<ll> primes;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    FOR(i, 1, n) {
        cin >> judge[i]._1;
        d = __gcd(d, judge[i]._1);
    }
    FOR(i, 1, n) cin >> judge[i]._2;
    if (d == 1) {
        cout << 0;
        return 0;
    }
    map<ll, vector<ll>> facs;
    FOR(i, 1, n) {
        ll prod = 1, g, now = judge[i]._1;
        while ((g = __gcd(now, d)) > 1) {
            now /= g;
            prod *= g;
        }
        facs[prod].eb(judge[i]._2);
    }
    FOR(i, 2, maxn - 123) if (d % i == 0) {
            primes.eb(i);
            while (d % i == 0) d /= i;
        }
    if (d > 1) primes.eb(d);
    int cnt = primes.size(), ALL = (1 << cnt) - 1;
    reset(dp, 0x3f);
    dp[0][0] = 0;
    for (const auto &now : facs) {
        vector<ll> tmp(now._2);
        sort(all(tmp));
        FOR(i, 1, int(tmp.size()) - 1) tmp[i] += tmp[i - 1];
        reset(to, 0x3f);
        to[0] = 0;
        REP(mask, 1 << cnt) {
            ll prod = 1, rem = now._1;
            REP(i, cnt) if ((1 << i) & mask) while (rem % primes[i] == 0) {
                        rem /= primes[i];
                        prod *= primes[i];
                    }
            if (prod > k) continue;
            ROF(mm, ALL, 0) if ((mask & mm) == mask) to[mm] = min(to[mm], to[mask ^ mm] + 1);
        }
        ROF(mm, ALL, 0) FOR(mask, 1, ALL) if ((mask & mm) == mask)
                    if (to[mask] <= tmp.size()) FOR(i, to[mask], cnt)
                                                  dp[i][mm] = min(dp[i][mm], dp[i - to[mask]][mask ^ mm] + tmp[to[mask] - 1]);
    }
    ll ans = inf;
    REP(i, cnt + 1) if (dp[i][ALL] < inf) ans = min(ans, i * dp[i][ALL]);
    if (ans < inf) cout << ans;
    else cout << -1;
}