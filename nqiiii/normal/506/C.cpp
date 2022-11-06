#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000;
int n, m, k, p, h[maxn + 10], a[maxn + 10];
ll cnt[maxn + 10], ned[maxn + 10];
ll ans;

struct hnode {
    int id; ll v;
    bool operator < (const hnode &t) const {
        return v > t.v;
    }
};

priority_queue<hnode> hp;


bool check(ll x) {
    while (!hp.empty()) hp.pop();
    for (int i = 1; i <= n; ++i) {
        ned[i] = h[i] + 1ll * m * a[i] - x;
        if (ned[i] > 0) {
            ned[i] = (ned[i] - 1) / p + 1;
            cnt[i] = 0;
            hp.push((hnode){i, x / a[i]});
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (hp.empty()) return 1;
        if (hp.top().v < i) return 0;
        for (int j = 1; j <= k; ++j) {
            if (hp.empty()) return 1;
            hnode t = hp.top(); hp.pop();
            ++cnt[t.id];
            if (cnt[t.id] < ned[t.id])
                hp.push((hnode){t.id, (x + 1ll * cnt[t.id] * p) / a[t.id]});
        }
    }
    return hp.empty();
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &p);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &h[i], &a[i]);
    for (ll l = 0, r = 1e18; l <= r; ) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid; r = mid - 1;
        } else l = mid + 1;
    }
    printf("%lld", ans);
}