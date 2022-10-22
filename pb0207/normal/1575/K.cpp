#include <bits/stdc++.h>
using namespace std;
#define int long long
const int p = 1e9 + 7;
int n, m, k, r, c;
inline int Qpow(int x, int y) {
    int ans = 1;
    for (; y; y >>= 1, x = 1ll * x * x % p)
        if (y & 1) ans = 1ll * ans * x % p;
    return ans;
}
struct Rec {
    int x, y, u, v;
    int Size() {
        if (u < x || v < y) return 0;
        return (u - x + 1) * (v - y + 1);
    }
} g[2];
signed main() {
    scanf("%lld%lld%lld%lld%lld", &n, &m, &k, &r, &c);
    for (int d = 0, x, y; d < 2; ++d) {
        scanf("%lld%lld", &x, &y);
        g[d] = {x, y, x + r - 1, y + c - 1};
    }
    int num;
    if (g[0].x == g[1].x && g[0].y == g[1].y) {
        num = n * m;
    } else {
        num = n * m - r * c;
    }
    printf("%lld\n", Qpow(k, num));
    return 0;
}