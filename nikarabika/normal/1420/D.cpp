//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 3e5 + 100;
const LL Mod = 998244353;
LL fac[maxn],
   inv[maxn];
int st[maxn],
    en[maxn];
vector<int> all;
int n, k;

LL Pow(LL x, LL y) {
    LL ans = 1,
       an = x;
    while (y) {
        if (y & 1LL)
            ans = ans * an % Mod;
        an = an * an % Mod;
        y >>= 1;
    }
    return ans;
}

LL comb(int x) {
    if (x < k)
        return 0;
    static bool comped = false;
    if (not comped) {
        fac[0] = 1;
        inv[0] = 1;
        for (int i = 1; i < maxn; i++) {
            fac[i] = (fac[i - 1] * i) % Mod;
            inv[i] = Pow(fac[i], Mod - 2);
        }
        comped = true;
    }
    LL ans = fac[x] * inv[x - k] % Mod;
    return ans * inv[k] % Mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> k;
    k--;
    for (int i = 0; i < n; i++) {
        cin >> st[i] >> en[i];
        all.PB(st[i]);
        all.PB(en[i]);
    }
    sort(all(all));
    all.resize(unique(all(all)) - all.begin());
    vector<pii> events;
    for (int i = 0; i < n; i++) {
        st[i] = lower_bound(all(all), st[i]) - all.begin();
        en[i] = lower_bound(all(all), en[i]) - all.begin();
        events.PB(MP(st[i], -1));
        events.PB(MP(en[i], +1));
    }
    sort(all(events));
    int cnt = 0;
    LL ans = 0;
    for (auto e: events) {
        if (e.R == -1)
            ans = (ans + comb(cnt)) % Mod;
        cnt -= e.R;
    }
    cout << ans << endl;
	return 0;
}