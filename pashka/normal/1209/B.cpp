#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<int> st(n);
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            st[i] = 1;
            c++;
        }
    }
    int res = c;
    for (int t = 1; t <= 100000; t++) {
        for (int i = 0; i < n; i++) {
            if (t >= b[i] && (t - b[i]) % a[i] == 0) {
                st[i] ^= 1;
                if (st[i]) c++; else c--;
            }
        }
        res = max(res, c);
    }
    cout << res;
    return 0;
}