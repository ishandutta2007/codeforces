#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n-1), c(n-2);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n-1; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n-2; i++) {
        cin >> c[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int pos = -1, err1, err2;
    for (int i = 0; i < n-1; i++) {
        if (a[i] != b[i]) {
            pos = i;
            break;
        }
    }

    if (pos == -1)
        err1 = a[n-1];
    else
        err1 = a[pos];

    pos = -1;

    for (int i = 0; i < n-2; i++) {
        if (b[i] != c[i]) {
            pos = i;
            break;
        }
    }

    if (pos == -1)
        err2 = b[n-2];
    else
        err2 = b[pos];

    cout << err1 << "\n" << err2;
    return 0;
}