#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];

void go(int u, int sum) {
    if (u == n + 1) {
        if (sum == 0) {
            cout << "YES" << endl;
            exit(0);
        }   
        return;
    }
    go(u + 1, (sum + a[u]) % 360);
    go(u + 1, (sum - a[u] + 360) % 360);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    go(1, 0);
    cout << "NO" << endl;
    return 0;
}