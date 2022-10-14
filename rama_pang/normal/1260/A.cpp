#include <bits/stdc++.h>
// #define TESTCASE
using namespace std;
using lint = long long;

void solve() {

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        lint c, sum;
        cin >> c >> sum;
        if (c >= sum) {
            cout << sum << "\n";
            continue;
        }
        vector<int> C(c);
        int cur = 0;
        while (sum--) {
            C[cur % c]++;
            cur++;
        }
        lint ans = 0;
        for (int i = 0; i < c; i++) {
            ans += C[i] * C[i];
        }
        cout << ans << "\n";
    }



}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tc = 1;

    #ifdef TESTCASE
    cin >> tc;
    #endif
    
    while (tc--) {
        solve();
    }
}