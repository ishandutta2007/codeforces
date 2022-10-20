#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[1]) {
            res = max(res, i - 1);
        }
        if (a[i] != a[n]) {
            res = max(res, n - i);
        }
    }
    cout << res << endl;
    return 0;
}