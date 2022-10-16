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

const ll MOD = 998244353;
const int maxn = 512;

int n, cnt[maxn];
ll a[maxn];
bool en[maxn], rem[maxn];
map<ll, int> mmap;

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%lld", &a[i]);
        bool flag = false;
        ROF(j, 4, 2) {
            ll now = pow(a[i], 1.0 / j) + 0.5;
            FOR(cur, now - 2, now + 2) {
                if (cur < 0) continue;
                ll c = 1;
                REP(_i, j) c *= cur;
                if (c == a[i]) {
                    mmap[cur] += j;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (!flag) en[i] = true;
    }
    FOR(i, 1, n) if (en[i]) rem[i] = true;
    FOR(i, 1, n) if (rem[i]) {
            ll g = 1;
            for (auto it : mmap) {
                g = __gcd(it._1, a[i]);
                if (g > 1) break;
            }
            if (g > 1) {
                mmap[g]++;
                mmap[a[i] / g]++;
                rem[i] = false;
                continue;
            }
            FOR(j, i + 1, n) if (rem[j]) {
                    if (a[i] == a[j]) continue;
                    g = __gcd(a[i], a[j]);
                    if (g > 1) {
                        mmap[g] += 2;
                        mmap[a[i] / g]++;
                        mmap[a[j] / g]++;
                        rem[i] = rem[j] = false;
                        break;
                    }
                }
        }

    FOR(i, 1, n) if (rem[i]) {
            cnt[i] = 1;
            rem[i] = false;
            FOR(j, i + 1, n)if (rem[j]) {
                    if (a[i] == a[j]) {
                        cnt[i]++;
                        rem[j] = false;
                    }
                }
        }
    ll ans = 1;
    for (auto it : mmap) ans = ans * (it._2 + 1) % MOD;
    FOR(i, 1, n) ans = ans * (cnt[i] + 1) % MOD * (cnt[i] + 1) % MOD;
    cout << ans << endl;
    return 0;
}