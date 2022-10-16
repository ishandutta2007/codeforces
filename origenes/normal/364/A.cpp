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

const int maxn = 4123;

char ss[maxn];
int a, n, s[maxn];
map<int, int> mmap;

int main() {
    scanf("%d", &a);
    scanf("%s", ss + 1);
    n = strlen(ss + 1);
    FOR(i, 1, n) s[i] = s[i - 1] + ss[i] - '0';
    if (!a) {
        int cnt[2] = {};
        FOR(i, 1, n) FOR(j, i, n) cnt[s[j] != s[i - 1]]++;
        ll ans = ll(cnt[0]) * cnt[0] + ll(cnt[0]) * cnt[1] * 2;
        printf("%lld\n", ans);
        return 0;
    }
    FOR(i, 1, n) FOR(j, i, n) mmap[s[j] - s[i - 1]]++;
    int upp = sqrt(a) + 0.5;
    ll ans = 0;
    FOR(i, 1, upp) if (a % i == 0)
            if (mmap.count(i) && mmap.count(a / i))
                ans += ll(mmap[i]) * mmap[a / i] * 2;
    if (upp * upp == a)
        ans = ans - ll(mmap[upp]) * mmap[upp];
    printf("%lld\n", ans);
    return 0;
}