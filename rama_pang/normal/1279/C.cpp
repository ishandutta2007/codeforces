#include <bits/stdc++.h>
#define TESTCASE
using namespace std;
using lint = long long;
int solve();
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    #ifdef TESTCASE
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    #else
    solve();
    #endif
    return 0;
}

int solve() {

    int N, M;
    cin >> N >> M;

    vector<int> A(N), pos(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        pos[A[i]] = i;
    }    

    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }


    vector<int> vis(N);
    int ptr = 0;
    lint ans = 0;
    for (int i = 0; i < M; i++) {
        // ptr = max(ptr, i);
        // bool in = false;
        // while (ptr < N && vis[B[i]] == 0) {
        //     vis[A[ptr]] = 1;
        //     ptr++;
        //     in = true;
        // }
        ptr = max(ptr, i);
        if (pos[B[i]] > ptr) {
            ans += pos[B[i]] + pos[B[i]] - i - i;
            ptr = pos[B[i]];
        }
        // cout << ans << " ";
    }
    ans += M;
    cout << ans << "\n";
}