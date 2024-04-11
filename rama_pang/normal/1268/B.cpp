#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint N;
lint A[300005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    lint black = 0, white = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i % 2 == 0) {
            black += A[i] / 2;
            white += (A[i] + 1) / 2;
        } else {
            black += (A[i] + 1) / 2;
            white += A[i] / 2;
        }
    }

    cout << min(black, white) << "\n";
}