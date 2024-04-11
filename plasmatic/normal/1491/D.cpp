// ./d-zookeeper-and-the-infinite-zoo.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e5 + 1, MB = 40;
int Q;

int pc(int k) { return __builtin_popcount(k); }

int U[MB], V[MB];

void apply(int u, int a[MB]) {
    for (auto i = 0; i < MB; i++) {
        a[i] = u & 1;
        u >>= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> Q;

    while (Q--) {
        int u, v; cin >> u >> v;
        if (u > v) cout << "NO\n";
        else {
            if (pc(u) < pc(v)) cout << "NO\n";
            else {
                memset(U, 0, sizeof U);
                memset(V, 0, sizeof V);
                apply(u, U); apply(v, V);

                bool good = true;
                int running = 0;
                for (auto i = 0; i < MB; i++) {
                    running -= V[i];
                    running += U[i];
                    good &= running >= 0;
                }

                cout << (good ? "YES\n" : "NO\n");
            }
        }
    }

    return 0;
}