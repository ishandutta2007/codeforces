#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define all(x) (x).begin(), (x).end()
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 123456;
const int upp = 100000;

int t, a, b, c, cnt[maxn];

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

void init() {
    FOR(i, 1, upp)for (int j = i; j <= upp; j += i)
            cnt[j]++;
}

int main() {
    init();
    scanf("%d", &t);
    REP(tt, t) {
        scanf("%d%d%d", &a, &b, &c);
        int u = gcd(a, b), v = gcd(a, c), w = gcd(b, c), x = gcd(u, v);
        ll tmp[8], ans = 0;
        tmp[7] = cnt[x];
        tmp[6] = cnt[u] - cnt[x];
        tmp[5] = cnt[v] - cnt[x];
        tmp[3] = cnt[w] - cnt[x];
        tmp[4] = cnt[a] - cnt[u] - cnt[v] + cnt[x];
        tmp[2] = cnt[b] - cnt[u] - cnt[w] + cnt[x];
        tmp[1] = cnt[c] - cnt[v] - cnt[w] + cnt[x];
        FOR(i, 1, 7) FOR(j, i + 1, 7) FOR(k, j + 1, 7) {
                    if ((i | j | k) != 7) continue;
                    ans += tmp[i] * tmp[j] * tmp[k];
                }
        FOR(i, 3, 7) {
            if (i == 4) continue;
            FOR(j, 1, 7) {
                if (i == j || (i | j) != 7) continue;
                ans += tmp[i] * (tmp[i] + 1) / 2 * tmp[j];
            }
        }
        ans += tmp[7] * (tmp[7] - 1) * (tmp[7] - 2) / 6 + tmp[7] * tmp[7];
        printf("%lld\n", ans);
    }
    return 0;
}