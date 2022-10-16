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

const int maxn = 15;

int a[maxn], n;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    REP(mask, 1 << n) {
        int now = 0;
        REP(i, n) {
            if (mask & (1 << i)) {
                now += a[i];
                if (now >= 360) now -= 360;
            } else {
                now -= a[i];
                if (now < 0) now += 360;
            }
        }
        if (!now) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}