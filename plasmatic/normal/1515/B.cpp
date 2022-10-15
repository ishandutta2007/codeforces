// ./b-phoenix-and-puzzle.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

int N;

bool isperf(ll k) {
    ll sq = 0;
    while (sq*sq<k) sq++;
    return sq*sq==k;
}

void solve() {
    cin >> N;
    bool ok = false;
    if (N % 2 == 0) ok |= isperf(N/2);
    if (N % 4 == 0) ok |= isperf(N/4);
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}