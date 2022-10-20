#include <bits/stdc++.h>

using namespace std;

const int N = 30010;

int t;
int n;
int a[N];
int b[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        long long neg = 0, pos = 0;
        for (int i = 1; i < n; i++) {
            int delta = a[i + 1] - a[i];
            if (delta > 0) pos += delta;
            else neg -= delta;
        }
        if (pos <= a[n] && neg <= a[1]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}