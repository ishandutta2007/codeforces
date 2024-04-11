// ./b-cat-cycle.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;

        if (N % 2 == 0) {
            K--;
            cout << (K%N+1) << '\n';
        }
        else {
            int gap = N / 2;
            if (K <= gap)
                cout << K << '\n';
            else {
                K += (K-1) / gap;
                K--;
                cout << (K%N+1) << '\n';
            }
        }
    }

    return 0;
}