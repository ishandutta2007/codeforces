#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N);
    for (auto& i : A) {
        cin >> i;
    }   
    for (auto& i : B) {
        cin >> i;
    }
    sort(begin(A), end(A));
    sort(begin(B), end(B));
    int ans = 2e9;
    for (int i = 0; i < N; i++) {
        int x = (B[i] + M - A[0]) % M;
        if (x < 0) {
            x += M;
        }
        vector<int> C;
        for (int j = 0; j < N; j++) {
            int n = (A[j] + x) % M;
            if (n < 0) {
                n += M;
            }
            C.emplace_back(n);
        }
        sort(begin(C), end(C));
        if (B == C) {
            ans = min(ans, x);
        }
    }

    cout << ans << "\n";
    return 0;
}