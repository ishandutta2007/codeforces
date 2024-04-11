#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
const int M = 5e5 + 10;
bitset<M> f;
int n;
vector<int> g[N];
int cnt[N];
int mnsi = 1e9, mnid;
inline int GetHp(int x, int fa) {
    int si = 1, mx = 0;
    for (auto y: g[x]) if (y != fa) {
        int tmp = GetHp(y, x);
        mx = max(mx, tmp);
        si += tmp;
    }
    mx = max(mx, n - si);
    if (mx < mnsi) mnid = x, mnsi = mx;
    return si;
}
int si[N];
int ans;
inline void GetAns(int x, int fa) {
    si[x] = 1;
    for (auto y: g[x]) if (y != fa) {
        GetAns(y, x);
        si[x] += si[y];
    }
    ans += si[x];
}
inline void Update(int x, int num) {
    for (int i = 1; num; i <<= 1) {
        int tmp = min(num, i);
        f |= f << (tmp * x);
        num -= tmp;
    }
}
signed main() {
    scanf("%lld", &n);
    for (int i = 2, x; i <= n; ++i) {
        scanf("%lld", &x);
        g[x].push_back(i);
        g[i].push_back(x);
    }
    GetHp(1, 0);
    int u = mnid;
    GetAns(u, 0);
    // cout << u << endl;
    // printf("%lld\n", ans);
    for (auto y: g[u]) ++cnt[si[y]];
    f[0] = 1;
    for (int i = 1; i <= n; ++i) if (cnt[i]) Update(i, cnt[i]);
    for (int i = n / 2; ~i; --i) if (f[i]) {
        // cout << i << endl;
        ans += i * (n - 1 - i);
        break; 
    } 
    printf("%lld\n", ans);
    return 0;
}