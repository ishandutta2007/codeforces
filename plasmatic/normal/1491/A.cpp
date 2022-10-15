// ./a-k-th-largest-value.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e5 + 1;
int N, Q, 
    cnt[2], A[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q;
    for (auto i = 0; i < N; i++) {
        int x; cin >> x;
        cnt[x]++;
        A[i] = x;
    }
    while (Q--) {
        int T, x; cin >> T >> x;
        if (T == 1) {
            x--;
            cnt[A[x]]--;
            A[x] ^= 1;
            cnt[A[x]]++;
        }
        else {
            cout << (x <= cnt[1]) << '\n';
        }
    }

    return 0;
}