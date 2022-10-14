#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int N, K, D;
        cin >> N >> K >> D;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        int ans = N;
        map<int, int> watch;
        for (int i = 0; i < D; i++) watch[A[i]]++;
        ans = watch.size();
        for (int i = D; i < N; i++) {
            watch[A[i]]++;
            watch[A[i - D]]--;
            if (watch[A[i - D]] == 0) {
                watch.erase(watch.find(A[i - D]));
            }
            ans = min(ans, (int)watch.size());
        }

        cout << ans << "\n";
    }
}