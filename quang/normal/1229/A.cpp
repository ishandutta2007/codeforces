#include <bits/stdc++.h>

using namespace std;

const int N = 7070;

int n;
long long a[N], b[N];
int can[N];

bool check(long long u, long long v) {
    return (u | v) == u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        if (can[i]) continue;
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i] == a[j]) {
                cnt++;
            }
        }
        if (cnt >= 2) {
            for (int j = 1; j <= n; j++) {
                if (a[i] == a[j]) {
                    can[j] = 1;
                    res += b[j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (can[i]) continue;
        int f = 0;
        for (int j = 1; j <= n; j++) {
            if (can[j] && check(a[j], a[i])) {
                f = 1;
                break;
            }
        }
        if (f) res += b[i];
    }
    cout << res << endl;
    return 0;
}