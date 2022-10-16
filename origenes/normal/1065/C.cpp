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

const int maxn = 123456;
const int inf = 0x3f3f3f3f;

int n, h[maxn << 1], t = inf, st = 0;
ll k, s[maxn << 1], col[maxn << 1];

int main() {
    scanf("%d%lld", &n, &k);
    FOR(i, 1, n) {
        scanf("%d", &h[i]);
        s[h[i]]++;
        t = min(t, h[i]);
        st = max(st, h[i]);
    }
    ROF(i, 2e5 + 5, t) {
        col[i] = col[i + 1] + s[i];
        s[i] = s[i + 1] + col[i];
    }
    int cnt = 0, p = st + 1;
    ROF(i, 2e5 + 5, t + 1) {
        if (s[i] - s[p] <= k && s[i - 1] - s[p] > k) {
            p = i;
            cnt++;
        }
    }
    if (p != t + 1) cnt++;
    printf("%d\n", cnt);
    return 0;
}