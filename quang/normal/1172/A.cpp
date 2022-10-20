#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N], b[N];
int x[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        x[b[i]] = i;
    }
    int pos = -1;
    for (int i = 1; i <= n; i++) {
        if (b[i] == 1) {
            pos = i;
        }
    }

    // 1 turn
    if (pos != -1) {
        int fail = 0;
        for (int i = pos + 1; i <= n; i++) {
            if (b[i] != b[i - 1] + 1) {
                fail = 1;
            }
        }
        if (!fail) {
            int needCheck = n - pos + 2;
            int f = 0;
            for (int i = needCheck; i <= n; i++) {
                if (x[i] + n + 1 > pos + i - 1) {
                    f = 1;
                    break;
                }
            }
            if (!f) {
                cout << pos - 1 << endl;
                return 0;
            }
        }
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int cur = x[i] + n + 1 + n - i;
        mx = max(mx, cur);
    }
    cout << mx - n << endl;
    return 0;
}