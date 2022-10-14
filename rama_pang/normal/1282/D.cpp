#include <bits/stdc++.h>
using namespace std;
using lint = long long;
// #define TESTCASE

/*
    1 query to find N
    N query to get string
    1 query to answer

    300 "a" = cntB + 300 - N = 300 - cntA
    300 "b" = cntA + 300 - N = 300 - cntB
    cntA + cntB = N

    2 queries to find n


*/
map<string, int> memo;
int query(string s) {
    if (memo.count(s)) {
        return memo[s];
    }
    cout << s << endl;
    int n;
    cin >> n;
    if (n == 0) {
        exit(0);
    }
    return memo[s] = n;
}

int solve() {
    int cntA = 300 - query(string(300, 'a'));
    int cntB = 300 - query(string(300, 'b'));
    int N = cntA + cntB;
    if (cntA == 0) {
        cout << string(N, 'b') << endl;
        return 0;
    } else if (cntB == 0) {
        cout << string(N, 'a') << endl;
        return 0;
    }

    // cout << N << " " << cntA << " " << cntB << "\n";
    string s(N, 'a'), t;
    memo[string(N, 'a')] = cntB;
    memo[string(N, 'b')] = cntA;
    for (int i = 0; i < N; i++) {
        t = s;
        s[i] = 'b';
        if (query(s) < query(t)) {
            cntB--;
        } else {
            s = t;
            cntA--;
        }
        if (cntA == 0 || cntB == 0) {
            if (cntB > 0) {
                for (int j = i + 1; j < N; j++) {
                    s[j] = 'b';
                }
            } else {
                for (int j = i + 1; j < N; j++) {
                    s[j] = 'a';
                }
            }
            break;
        }
    }
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    #ifdef TESTCASE
    cin >> T;
    while (T--) {
        solve();
    }
    #else
    solve();
    #endif
    return 0;
}