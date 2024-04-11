// ./a-balance-the-bits.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 2e5 + 1;
int N;
string s;

bool check(string &s) {
    int c = 0;
    for (auto c : s) {
        if (c == '(') c++;
        else {
            c--;
            if (c < 0) return false;
        }
    }
    return c == 0;
}

void solve() {
    cin >> N >> s;
    
    if (s[0] == '0' || s[N-1] == '0') {
        cout << "NO\n";
        return;
    }

    int c0 = 0; //, inRow = 0;
    for (auto c : s) {
        if (c == '0') {
            c0++;
            // inRow++;
            // if (inRow > 2) {
            //     cout << "NO\n";
            //     return;
            // }
        }
        else {
            // inRow = 0;
        }
    }
    if (c0 % 2) {
        cout << "NO\n";
        return;
    }

    string t(N, 'X');
    // int fl = 0;
    // for (auto i = 0; i < N; i++) {
    //     if (s[i] == '0') {
    //         if (fl == 0) {
    //             if (t[i-1] != 'X' || s[i-1] != '1') {
    //                 cout << "NO\n";
    //                 return;
    //             }
    //             t[i-1] = '(';
    //             t[i] = ')';
    //         }
    //         else {
    //             if (t[i+1] != 'X' || s[i+1] != '1') {
    //                 cout << "NO\n";
    //                 return;
    //             }
    //             t[i+1] = ')';
    //             t[i] = '(';
    //         }
    //
    //         fl = !fl;
    //     }
    // }

    // int rcnt = 0;
    // for (auto c : t)
    //     if (c == 'X')
    //         rcnt++;
    // rcnt /= 2;

    int c1 = N-c0, fl = 0;
    c1 /= 2;
    for (auto i = 0; i < N; i++) {
        if (s[i] == '1') {
            if (c1 > 0) t[i] = '(';
            else t[i] = ')';
            c1--;
        }
        else {
            t[i] = fl ? ')' : '(';
            fl ^= 1;
        }
    }

    string tt(N, 'X');
    for (auto i = 0; i < N; i++) {
        if (s[i] == '1') tt[i] = t[i];
        else tt[i] = t[i] == '(' ? ')' : '(';
    }

    if (check(t) && check(tt))
        cout << "YES\n" << t << '\n' << tt << '\n';
    else 
        cout << "NO\n";
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