// ./e-post-lamps.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e6 + 1;
int N, M, K,
    S[MN];
bool tk[MN*2];

int dsu[MN];
int rt(int x) { 
    if (x >= N) return x;
    return dsu[x] == x ? x : dsu[x] = rt(dsu[x]);
}
void unite(int t, int f) { dsu[rt(f)] = rt(t); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    iota(dsu, dsu + N, 0);
    for (auto i = 0; i < M; i++) {
        cin >> S[i];
        if (S[i] > 0)
            unite(S[i]-1, S[i]);
        else {
            cout << "-1\n";
            return 0;
        }
        // printf("t=%d\n",S[i]);
    }

    // harmonic series kekw
    ll ans = LLINF;
    for (auto i = 1; i <= K; i++) {
        ll c; cin >> c;

        ll cans = 0;
        int cur = 0;
        // int its=10;
        while (cur < N) {
            int nxt = rt(cur + i);
            // printf("i=%d cur=%d nxt=%d cans=%lld t=%d\n", i,cur,nxt,cans,tk[nxt]);
            // fflush(stdout);
            // assert(its--);
            if (nxt == cur) {
                cans = LLINF;
                break;
            }

            cans += c;
            cur = nxt;
        }

        // printf("i=%d cans=%lld\n", i,cans);
        ans = min(ans, cans);
    }

    cout << (ans == LLINF ? -1 : ans) << '\n';

    return 0;
}