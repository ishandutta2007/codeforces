#include <bits/stdc++.h>
#define debug(x) cerr << ">>>> " << #x << " is " << x << endl
#define testcase int TESTCASE; cin >> TESTCASE; while (TESTCASE--)
using namespace std;
using lint = long long;
using loat = long double;

const lint MOD = (lint)1e9 + 7;
const loat PI = cos((loat)-1);

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> A(n), B(n), C(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> B[i];
        }
        for (int i = 0; i < n; i++) {
            C[i] = B[i] - A[i];
        }

        for (int i = 0; i < n; i++) {
            if (C[i] > 0) {
                int cur = i;
                while (cur < n && C[cur] > 0) {
                    cur++;
                }
                for (int j = i; j < cur; j++) {
                    A[j] += C[i];
                }
                break;
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cout << A[i];
        // }
        if (A != B) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }    

    return 0;
}