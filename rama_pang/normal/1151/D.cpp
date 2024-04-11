#include <bits/stdc++.h>
using namespace std;
using lint = long long;
/*  
    Assign j such that
    (a - b) * j + bn - a
    is minimized.

    bn - a is constant, so sort by (a - b) and assign


*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    lint ans = 0;
    sort(begin(A), end(A), [&](auto a, auto b) {
        return (a.first - a.second) > (b.first - b.second);
    });

    for (int i = 1; i <= N; i++) {
        ans += (1ll * (A[i - 1].first - A[i - 1].second) * i);
        ans += 1ll * A[i - 1].second * N - A[i - 1].first;
    }
    cout << ans << "\n";

}