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
    long a = 0;
    long b = 0;
    long c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'v') {
            if (i > 0 && s[i - 1] == 'v') {
                a++;
                c += b;
            }
        } else {
            b += a;
        }
    }
    cout << c << "\n";
    return 0;
}