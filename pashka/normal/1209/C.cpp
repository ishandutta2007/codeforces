#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

void solve_test() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (char m = '0'; m <= '9'; m++) {
        int l = n;
        int r = -1;
        char lb = '0';
        char ls = '0';
        bool ok = true;
            for (int i = 0; i < n; i++) {
            if (s[i] > m) {
                l = min(l, i);
                if (s[i] < lb) {
                    ok = false;
                }
                lb = s[i];
            }
            if (s[i] < m) {
                r = max(r, i);
                if (s[i] < ls) {
                    ok = false;
                }
                ls = s[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == m) {
                if (i > l && i < r) {
                    ok = false;
                }
            }
        }
        if (ok) {
            for (int i = 0; i < n; i++) {
                if (s[i] < m) {
                    cout << '1';
                } else if (s[i] > m) {
                    cout << '2';
                } else {
                    if (i < l) {
                        cout << '2';
                    } else {
                        cout << '1';
                    }
                }
            }
            cout << "\n";
            return;
        }
    }
    cout << "-\n";
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) solve_test();

    return 0;
}