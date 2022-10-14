#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    lint ans = 1ll * N * ((1ll * N * (N + 1) / 2));
    // cout << ans << "\n";
    for (int i = 1; i < N; i++) {
        lint lo = A[i - 1], hi = A[i];
        if (lo > hi) swap(lo, hi);
        lint exist = 1ll * lo * (N - hi + 1);
        ans -= exist;
    }
    // cout << ans << "\n";
    for (int i = 0; i < N; i++) {
        lint a = A[i] - 1;
        ans -= 1ll * a * (a + 1) / 2;
        a = N - A[i];
        ans -= 1ll * a * (a + 1) / 2;
    }
    cout << ans << "\n";

}