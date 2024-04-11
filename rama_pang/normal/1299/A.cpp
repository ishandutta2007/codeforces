#include <bits/stdc++.h>
using namespace std;

// #define TESTCASE

#define all(x) begin(x), end(x)
#define sz(x) x.size()

void solve();
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    #ifdef TESTCASE
    cin >> T;
    #else
    T = 1;
    #endif

    while (T--) {
        solve();
    }
}


void solve() {

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int ans = 0;
    vector<int> bits(30);
    for (int j = 0; j < 30; j++) {
        for (int i = 0; i < N; i++) {
            if (A[i] & (1 << j)) {
                bits[j]++;
            }
        }
    }
    int mx = 0, where = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 30; j++) {
            if (A[i] & (1 << j)) {
                bits[j]--;
            }
        }
        int cur = A[i];
        for (int j = 0; j < 30; j++) {
            if (bits[j]) {
                if (cur & (1 << j)) {
                    cur ^= (1 << j);
                }
            }
        }
        if (cur > mx) {
            mx = cur;
            where = i;
        }
        for (int j = 0; j < 30; j++) {
            if (A[i] & (1 << j)) {
                bits[j]++;
            }
        }
    }

    swap(A[0], A[where]);

    // cout << mx << "\n";

    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    } cout << "\n";

    

}