#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cur = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] > cur + 1) {
            cout << i << endl;
            return 0;
        }
        cur = max(cur, a[i]);
    }
    cout << -1 << endl;
    return 0;
}