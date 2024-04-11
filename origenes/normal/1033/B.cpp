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

ll a, b;
int t;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &a, &b);
        if (a - b > 1) {
            puts("NO");
            continue;
        }
        ll upp = sqrt(a + b) + 0.5;
        ll now = a + b;
        FOR(i, 2, upp) {
            if (now % i == 0) {
                puts("NO");
                goto label;
            }
        }
        puts("YES");
        label:;
    }
    return 0;
}