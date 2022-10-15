// ./a-phoenix-and-gold.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 101;
int N, X,
    A[MN];

void solve() {
    cin >> N >> X;

    int sum = 0;
    for (auto i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    sort(A, A+N);

    if (sum == X) cout << "NO\n";
    else {
        cout << "YES\n";
        vector<bool> skip(N);
        int cs = 0;
        for (auto i = 0; i < N; i++) {
            if (cs+A[i] == X) {
                skip[i] = true;
            }
            else {
                cs += A[i];
                cout << A[i] << ' ';
            }
        }
        for (auto i = 0; i < N; i++)
            if (skip[i])
                cout << A[i] << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}