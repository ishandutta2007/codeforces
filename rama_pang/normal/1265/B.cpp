#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N), pos(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            pos[A[i] - 1] = i;
        }
        vector<int> ans(N, 0);
        int l = pos[0], r = pos[0];
        ans[0] = 1;
        for (int i = 1; i < N; i++) {
            l = min(l, pos[i]);
            r = max(r, pos[i]);
            if (r - l == i) {
                ans[i] = 1;
            }
        }

        for (auto i : ans) cout << i;
        cout << "\n";
    }
    return 0;
}