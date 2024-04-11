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

    string s;
    cin >> s;

    int n = s.size();

    int l = 0;
    int r = n - 1;

    string sl;
    string sr;

    while (r - l + 1 >= 4) {
        for (int i = 0; i < 4; i++) {
            char cl = s[l + (i / 2)];
            char cr = s[r - (i % 2)];
            if (cl == cr) {
                sl += cl;
                sr += cr;
                break;
            }
        }
        l += 2;
        r -= 2;
    }
    if (r >= l) {
        sl += s[l];
    }
    reverse(sr.begin(), sr.end());
    cout << sl << sr << "\n";
    return 0;
}