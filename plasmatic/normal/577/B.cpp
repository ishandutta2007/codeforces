// ./b-modulo-sum.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 2e3 + 1;
int N, M;
bitset<MN> cur;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (auto i = 0; i < N; i++) {
        int x; cin >> x;
        x %= M;
        cur |= cur << x;
        cur[x] = true;
        cur |= cur >> M;
    }
    cout << (cur[0] ? "YES\n" : "NO\n");

    return 0;
}