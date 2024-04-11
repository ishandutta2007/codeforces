#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N; cin >> N;
    lint A[N + N] = {};
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    lint pref[N + N] = {}, cnt[2][2000005];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= N; i++) {
        pref[i] = A[i] ^ pref[i - 1];
    }
    lint ans = 0;
    lint x = 0;
    cnt[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        x ^= A[i];
        ans += cnt[i % 2][x];
        cnt[i % 2][x]++;
    }
    cout << ans << "\n";
}