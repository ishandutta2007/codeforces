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

ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int n;

int main() {
    scanf("%d", &n);
    ll ans = 0;
    ll a, b;
    REP(i, n) {
        scanf("%lld%lld", &a, &b);
        ans = gcd(lcm(a, b), ans);
    }
    if (ans == 1) {
        puts("-1");
        return 0;
    }
    ll d = gcd(a, ans);
    ans = d > 1 ? d : gcd(b, ans);
    for (ll i = 2; i <= sqrt(ans) + 1; i++) {
        if (ans % i == 0) {
            printf("%lld\n", i);
            return 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}