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
    int n1 = 0;
    int n0 = 0;
    for (char c : s) {
        if (c == 'z') n0++;
        if (c == 'n') n1++;
    }
    for (int i = 0; i < n1; i++) {
        cout << "1 ";
    }
    for (int i = 0; i < n0; i++) {
        cout << "0 ";
    }

    return 0;
}