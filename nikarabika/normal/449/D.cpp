#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define L first
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define R second
#define smin(x, y) (x) = min((x), (y))
#define PB push_back
#define MP make_pair
#define all(x) (x).begin(),(x).end()

const int maxn = 1024 * 1024,
      maxl = 20;
const LL Mod = 1000 * 1000 * 1000 + 7;
int cnt[maxl+1][maxn],
    pw[maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    pw[0] = 1;
    for (int i = 1; i < maxn; i++)
        pw[i] = pw[i - 1] * 2 % Mod;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[0][x]++;
    }
    for (int i = 1; i <= maxl; i++) {
        int idx = i - 1;
        for (int mask = 0; mask < (1 << maxl); mask++) {
            int bit = (mask >> idx) & 1;
            cnt[i][mask] = cnt[i - 1][mask];
            if (bit == 0)
                cnt[i][mask] += cnt[i - 1][mask ^ (1 << idx)];
        }
    }
    LL ans = 0;
    for (int mask = 0; mask < (1 << maxl); mask++) {
        if (__builtin_popcount(mask) & 1)
            ans -= pw[cnt[maxl][mask]];
        else
            ans += pw[cnt[maxl][mask]];
    }
    ans = (ans % Mod + Mod) % Mod;
    cout << ans << '\n';
    return 0;
}