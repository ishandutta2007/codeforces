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
const int MOD = 1e9 + 7;

int n, g, mo[maxn], a[maxn], cnt[maxn], C[maxn];
bool prime[maxn];

void init() {
    REP(i, maxn) mo[i] = prime[i] = true;
    mo[0] = 0;
    FOR(i, 2, floor(sqrt(maxn)) + 0.5) if (prime[i]) {
            for (int j = i * i; j < maxn; j += i * i) mo[j] = 0;
            for (int j = i * i; j < maxn; j += i) prime[j] = false;
        }
    FOR(i, 2, maxn - 1) if (prime[i]) for (int j = i; j < maxn; j += i) mo[j] = -mo[j];
    FOR(i, 1, maxn - 1) for (int j = 2 * i; j < maxn; j += i) cnt[i] += cnt[j];
    FOR(i, 1, maxn - 1) C[i] = i;

}

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", a + i);
        if (a[i] == 1) {
            puts("1");
            return 0;
        }
        g = __gcd(g, a[i]);
        cnt[a[i]] = 1;
    }
    if (g > 1) {
        puts("-1");
        return 0;
    }
    init();
    FOR(ans, 2, 7) {
        int now = 0, pre = 0;
        FOR(i, 1, maxn - 1) {
            int tmp = C[i];
            C[i] = (C[i - 1] + pre) % MOD;
            pre = tmp;
        }
        FOR(i, 1, maxn - 1) now = (now + C[cnt[i]] * mo[i]) % MOD;
        if (now) {
            printf("%d\n", ans);
            return 0;
        }
    }
}