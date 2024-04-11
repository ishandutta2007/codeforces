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
    sort(a.begin(), a.end());
    if (a[n - 1] == 0) {
        cout << "cslnb";
        return 0;
    }
    int c = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) c++;
    }
    if (c > 1) {
        cout << "cslnb";
        return 0;
    }
    if (c == 1) {
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) {
                if (a[i] == 0 || (i > 0 && a[i - 1] == a[i] - 1)) {
                    cout << "cslnb";
                    return 0;
                }
            }
        }
    }
    long s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i] - i;
    }
    if (s % 2 == 1) {
        cout << "sjfnb";
    } else {
        cout << "cslnb";
    }

    return 0;
}