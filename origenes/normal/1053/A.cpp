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

int main() {
    ll n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    if (n * m * 2 % k) {
        puts("NO");
        return 0;
    }
    bool flag = true;
    if (k & 1) flag = false;
    if (flag) k >>= 1;
    ll now = __gcd(n, k);
    k /= now;
    ll x = n / now;
    now = __gcd(m, k);
    k /= now;
    ll y = m / now;
    if (!flag)
        x < n ? x += x : y += y;
    puts("YES");
    puts("0 0");
    printf("%lld 0\n", x);
    printf("0 %lld\n", y);
    return 0;
}