// ./c-pekora-and-trampoline.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 5011;
int N,
    dsu[MN];
ll S[MN];

void init() { iota(dsu, dsu+N+2, 0); }
int rt(int x) { return dsu[x] == x ? x : dsu[x] = rt(dsu[x]); }
void unite(int to, int from) { dsu[rt(from)] = rt(to); }

void solve() {
    cin >> N;
    for (auto i = 0; i < N; i++) {
        cin >> S[i];
    }

    init();
    ll ans = 0;
    for (auto i = 0; i < N; i++)
        if (S[i] == 1)
            unite(i+1, i);
    for (auto i = 0; i < N; i++) {
        if (S[i] > N-i) {
            ans += S[i] - (N-i);
            S[i] = N-i;
        }
        if (S[i] == 1) unite(i+1, i);

        // printf("i=%d S[i]=%lld ans=%lld\n", i, S[i], ans);
        while (S[i] > 1) {
            ans++;
            for (int c = i; c < N; ) {
                // printf("c=%d, sc=%lld ans=%lld\n", c, S[c], ans);
                int pre = c;
                if (c+S[c] < N) c = rt(c+S[c]);
                else c += S[c];
                if (--S[pre] == 1) unite(pre+1, pre);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        // printf("case\n");
        solve();
    }

    return 0;
}