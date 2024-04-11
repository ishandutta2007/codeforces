// ./b-minimal-cost.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 101, MC = 1e6+1;
int N,
   A[MN];
ll U, V;

void solve() {
    map<int, int> colcnt;
    cin >> N >> U >> V;
    int maxdiff = 0;
    for (auto i = 1; i <= N; i++) {
        cin >> A[i];
        colcnt[A[i]]++;
        if (i > 1) {
            maxdiff = max(maxdiff, abs(A[i] - A[i-1]));
        }
    }
    if (maxdiff == 0) {
        // move right 2 or right+up
        cout << min(2*V, U+V) << '\n';
    }
    else if (maxdiff == 1) {
        // move right or up
        cout << min(U, V) << '\n';
    }
    else {
        cout << 0 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}