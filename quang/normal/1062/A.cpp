#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a[N];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int last = 0;
    int res = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1] + 1) {
            last = a[i];
        }
        res = max(res, a[i] - last - 1);
    }
    if (a[n] == 1000) res = max(res, 1000 - last);
    cout << res << endl;
    return 0;
}