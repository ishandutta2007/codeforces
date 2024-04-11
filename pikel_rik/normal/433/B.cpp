#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> a(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<ll> b = a;
    sort(b.begin(), b.end());

    for (int i = 2; i <= n; i++) {
        a[i] += a[i-1];
        b[i] += b[i-1];
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r, type;
        cin >> type >> l >> r;

        if (type == 1)
            cout << a[r] - a[l-1] << "\n";
        else
            cout << b[r] - b[l-1] << "\n";
    }

    return 0;
}