#include <bits/stdc++.h>
    #ifdef PoDuReM
        #define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
    #else
        #define err(...) 42
    #endif

typedef long long ll;

using namespace std;

#define TASK ""
#define multiTest 0

void solve();
int main() {
    #ifndef PoDuReM 
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (!strcmp(TASK, "input")) {
            assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
        } else if (strcmp(TASK, "")) {
            assert(freopen(TASK".in", "r", stdin)); assert(freopen(TASK".out", "w", stdout));
        }
    #endif
    int t = 1;
    if (multiTest) {
        cin >> t;
    }
    while (t--) solve();
    return 0;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> cnt1(m);
    cnt1[0] = n / m;
    for (int i = 1; i < m; ++i) {
        cnt1[i] = n / m + (n % m >= i);
    }
    vector<ll> cnt2(m);
    for (int i = 0; i < m; ++i) {
        cnt2[i * i % m] += cnt1[i];
    }
    for (int i = 0; i < m; ++i) err("cnt[%d] = %d\n", i, cnt2[i]);
    ll ans = 0;
    for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j) if ((i + j) % m == 0) {
        ans += cnt2[i] * cnt2[j];
    }
    cout << ans << "\n";
}