#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long> p(n);
    for (int i = 0; i < n; i++) {
        if (i - m >= 0) {
            p[i] = p[i - m] + a[i];
        } else {
            p[i] = a[i];
        }
    }

    long s = 0;
    for (int i = 0; i < n; i++) {
        s += p[i];
        cout << s << " ";
    }
    cout << "\n";

    return 0;
}