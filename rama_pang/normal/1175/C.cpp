#include <bits/stdc++.h>
#define TESTCASE
using namespace std;
using lint = long long;

void solve() {
    srand(time(NULL));
    lint N, K; cin >> N >> K;
    vector<lint> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    pair<lint, lint> ans = {1e10, -1};


    for (int i = 0; i + K < N; i++) {
        lint dist = A[i + K] - A[i];
        ans = min(ans, make_pair(dist, A[i] + dist / 2));
    }

    cout << ans.second << "\n";

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int tc = 1;
    #ifdef TESTCASE
    cin >> tc;
    #endif

    while (tc--) solve();
}