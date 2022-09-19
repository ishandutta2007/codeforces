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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool x = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            cout << a[i] / 2;
        } else {
            if (x) {
                cout << (a[i] + 1) / 2;
            } else {
                cout << (a[i] - 1) / 2;
            }
            x ^= 1;
        }
        cout << "\n";
    }

    return 0;
}