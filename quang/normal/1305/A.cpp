#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int n;
int a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
            for (int i = 1; i <= n; i++) cin >> b[i];
        sort(a + 1,a + n + 1);
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        for (int i = 1; i <= n; i++) {
            cout << b[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}