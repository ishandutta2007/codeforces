#include <bits/stdc++.h>
// #define TESTCASE
using namespace std;
using lint = long long;

void solve() {
    
    lint N, K; cin >> N >> K;
    vector<lint> A(N), suff(N);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = N - 1; i >= 0; i--) {
        suff[i] = A[i];
        if (i < N - 1) {
            suff[i] += suff[i + 1];
        }
    }

    
    sort(suff.begin() + 1, suff.end(), greater<lint>());
    lint ans = 0;
    for (int i = 0; i < K; i++) {
        ans += suff[i];
    }

    cout << ans << "\n";

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