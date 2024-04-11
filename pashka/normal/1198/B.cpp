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
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    vector<int> b(q);
    for (int i = 0; i < q; i++) {
        int c;
        cin >> c;
        if (c == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            a[p] = x;
            t[p] = i;
        } else {
            int x;
            cin >> x;
            b[i] = x;
        }
    }
    for (int i = q - 2; i >= 0; i--) {
        b[i] = max(b[i], b[i + 1]);
    }
    for (int i = 0; i < n; i++) {
        a[i] = max(a[i], b[t[i]]);
        cout << a[i] << " ";
    }



    return 0;
}