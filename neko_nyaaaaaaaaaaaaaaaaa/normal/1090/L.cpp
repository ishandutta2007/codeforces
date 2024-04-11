#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll T, N, A, B, K;
// bool f(int x) {

// }
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T >> N >> A >> B >> K;
    ll l = 0, r = T + 1;
    ll numA = (N + 1) / 2;
    ll numB = N / 2;
    while (true) {
        if (l >= r - 1)
            break;
        ll mid = (l + r) / 2;
        ll numT = mid;
        ll curA = min(A, numT), curB = min(B, numT);
        if ((curA * numA + curB * numB) / numT >= K) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
}