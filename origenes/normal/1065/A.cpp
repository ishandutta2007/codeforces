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

int t;
ll s, a, b, c;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld%lld%lld", &s, &a, &b, &c);
        ll pk = a * c;
        ll ans = s / pk * (a + b) + s % pk / c;
        printf("%lld\n", ans);
    }
    return 0;
}