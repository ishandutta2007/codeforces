#include <bits/stdc++.h>
using namespace std;

const int MAX = 5000;

int N, Pos, K;
int A[MAX];

void solve() {
    cin >> N >> Pos >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    K = min(K, Pos - 1);
    int ans = 0;
    for (int pick = 0; pick <= K; pick++) { // force someone to pick front
        int cur = 1e9 + 5;
        for (int opp = 0; opp <= Pos - K - 1; opp++) {
            cur = min(cur, max(A[pick + opp + 1], A[N - (Pos - (pick + opp)) + 1]));
        }
        ans = max(ans, cur);
    }

    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}