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

const int maxn = 212345;

int a[maxn], v[35], n, s, ans;

bool check(int now) {
    REP(i, 31) if (now & (1 << i)) {
            if (!v[i]) {
                v[i] = now;
                return true;
            }
            now ^= v[i];
        }
    return false;
}

int main() {
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", a + i);
        s ^= a[i];
    }
    if (!s) {
        puts("-1");
        return 0;
    }
    ROF(i, n, 1) ans += check(a[i]);
    printf("%d", ans);
}