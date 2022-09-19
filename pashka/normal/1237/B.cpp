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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    vector<int> c(n);
    for (int i = 0; i < n; i++) c[a[i]] = i;

    int m = n;
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (c[b[i]] > m) {
            res++;
        }
        m = min(m, c[b[i]]);
    }
    cout << res;

    return 0;
}