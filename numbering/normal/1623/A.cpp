#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, M;
        cin >> N >> M;
        int rb, cb, rd, cd;
        cin >> rb >> cb >> rd >> cd;
        int ans = min((rb <= rd ? rd - rb : 2*N - rb - rd), (cb <= cd ? cd - cb : 2*M - cb - cd));
        cout << ans << '\n';
    }
}