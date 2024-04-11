#include <bits/stdc++.h>
#define testcase int TESTCASE; cin >> TESTCASE; while (TESTCASE--)
#define db(x) cout << #x << " is " << x << "\n"
using namespace std;
using lint = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    testcase {
        int N, M; cin >> N >> M;
        vector<int> A(N), deg(N);
        map<pair<int, int>, int> mp;
        for (int i = 0; i < N; i++) cin >> A[i];
        lint ans = 0;
        if (N == 2) {
            cout << -1 << "\n";
            continue;
        }
        if (M < N) {
            cout << -1 << "\n";
            continue;
        }

        for (int i = 0; i < N; i++) ans += A[i];
        ans *= 2;
        
        M -= N;
        lint b1 = 1e9, b2 = 1e9;
        int id1, id2;
        for (int i = 0; i < N; i++) {
            if (b1 > A[i]) {
                b2 = b1;
                b1 = A[i];
                id2 = id1;
                id1 = i;
            } else if (b2 > A[i]) {
                b2 = A[i];
                id2 = i;
            }
        }
        
        ans += (b1 + b2) * M;
        cout << ans << "\n";
        for (int i = 0; i < N; i++) {
            cout << (i % N) + 1 << " " << ((i + 1) % N) + 1 << "\n"; 
        }
        while (M--) {
            cout << id1 + 1 << " " << id2 + 1 << "\n";
        }

    }    

}