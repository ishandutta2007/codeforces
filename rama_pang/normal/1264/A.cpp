#include <bits/stdc++.h>
#define TESTCASE
using namespace std;
using lint = long long;


int solve() {

    int N; cin >> N;
    vector<int> A(N);
    int G = 0, S = 0, B = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }    
    if (N <= 5) {
        cout << "0 0 0\n";
        return 0;
    }

    int last = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] < A[0]) {
            G = i;
            last = i;
            break;
        }
    }

    for (int i = last; i < N; i++) {
        if (i - last <= G) continue;
        if (A[i - 1] > A[i] && i - last > G) {
            S = i - last;
            last = i;
            break;
        }
    }
    
    for (int i = last; i < N; i++) {
        if (i - last <= G) continue;
        if (A[i - 1] > A[i] && i - last > G) {
            B = i - last;
            last = i;
            break;
        }
    }
    
    if (G + S + B > (N / 2) || G >= S || G >= B) {
        cout << "0 0 0\n";
        return 0;
    }

    int lastB = B;
    for (int i = last + 1; i < N; i++) {
        if (A[i - 1] > A[i]) {
            lastB += i - last;
            if (G + S + lastB > (N / 2)) {
                break;
            }
            B = lastB;
            last = i;
        }
    }

    cout << G << " " << S << " " << B << "\n";

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int Testcase = 1;
    
    #ifdef TESTCASE
    cin >> Testcase;
    #endif

    for (int tc = 1; tc <= Testcase; tc++) {
        solve();
    }

    return 0;
}