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

ll n;

int main() {
    scanf("%lld", &n);
    if (n < 10) {
        printf("%lld\n", n);
        return 0;
    }
    ll a = 9;
    while (a <= n)
        a = a * 10 + 9;
    a = (a - 9) / 10;
    ll b = n - a;
    int ans = 0;
    while (a) {
        ans += a % 10;
        a /= 10;
    }
    while (b) {
        ans += b % 10;
        b /= 10;
    }
    printf("%d\n", ans);
    return 0;
}