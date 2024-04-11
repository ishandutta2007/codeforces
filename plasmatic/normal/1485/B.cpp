// ./b-replace-and-keep-sorted.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e5 + 10;
int N, Q, K,
    A[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q >> K;
    for (int i = 1; i <= N; i++) cin >> A[i];
    A[0] = 0; A[N+1] = K+1;
    while (Q--) {
        int l, r; cin >> l >> r;
        int ans = (A[r] - A[l] + 1 - (r - l + 1)) * 2 + (K - A[r]) + (A[l] - 1);
        cout << (ans) << '\n';
    }

    return 0;
}