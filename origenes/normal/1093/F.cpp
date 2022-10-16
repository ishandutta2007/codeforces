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

const int maxk = 112;
const ll MOD = 998244353;

ll s[maxk], ans, tot;
deque<ll> dp[maxk];

int n, k, len;

void ins(int now) {
    ll cur = (ans + MOD - s[now]) % MOD;
    dp[now].push_front(cur);
    s[now] = (s[now] + cur) % MOD;
    tot = (tot + cur) % MOD;
    if (dp[now].size() == len) {
        s[now] = (s[now] + MOD - dp[now].back()) % MOD;
        tot = (tot + MOD - dp[now].back()) % MOD;
        dp[now].pop_back();
    }
}

int main() {
    scanf("%d%d%d", &n, &k, &len);
    if (len == 1) {
        puts("0");
        return 0;
    }
    int now;
    scanf("%d", &now);
    if (now > 0) now--;
    if (now > -1) {
        dp[now].pb(1);
        s[now] = ans = 1;
    } else {
        REP(i, k) {
            dp[i].pb(1);
            s[i] = 1;
            ans++;
        }
    }
    FOR(i, 1, n - 1) {
        scanf("%d", &now);
        if (now > 0) now--;
        if (now > -1) {
            tot = ans;
            ins(now);
            ans = tot;
            REP(j, k) if (j != now) {
                    dp[j].clear();
                    ans = (ans + MOD - s[j]) % MOD;
                    s[j] = 0;
                }
        } else {
            tot = ans;
            REP(j, k) ins(j);
            ans = tot;
        }
    }
    printf("%lld", ans);
}