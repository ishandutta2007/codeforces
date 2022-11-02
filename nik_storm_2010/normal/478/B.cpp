#include <cstdio>

using namespace std;
typedef long long ll;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    ll k1 = n % m;
    ll k0 = m - k1;
    ll ans1 = k1 * (n / m + 1) * (n / m) / 2 + k0 * (n / m) * (n / m - 1) / 2;
    ll ans2 = (n - m + 1LL) * (n - m) / 2;
    printf("%I64d %I64d\n", ans1, ans2);
    return 0;
}