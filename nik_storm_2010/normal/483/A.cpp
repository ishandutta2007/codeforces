#include <cstdio>

using namespace std;
typedef long long ll;

ll gcd(ll x, ll y) {
    if (y == 0) return x; else return gcd(y, x % y);
}

int main() {
    ll l, r;
    scanf("%I64d %I64d", &l, &r);
    for (ll i = l; i <= r; i++) for (ll j = i + 1; j <= r; j++) for (ll k = j + 1; k <= r; k++) if (gcd(i, j) == 1 && gcd(j, k) == 1 && gcd(i, k) != 1) {
        printf("%I64d %I64d %I64d\n", i, j, k);
        return 0;
    }
    puts("-1");
    return 0;
}