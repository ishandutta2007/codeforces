#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int LOG = 61;

int n;
long long a[N];

bool check(long long u, int pos) {
    long long v = (u >> pos);
    v <<= pos;
    if (u != v) return 0;
    return u >> pos & 1ll;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int maxPos = -1;
    int maxRes = 0;
    for (int i = 0; i < LOG; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (check(a[j], i)) {
                cnt++;
            }
        }
        if (cnt > maxRes) {
            maxRes = cnt;
            maxPos = i;
        }
    }
    cout << n - maxRes << endl;
    for (int i = 1; i <= n; i++) {
        if (!check(a[i], maxPos)) {
            cout << a[i] << ' ';
        }
    }
    cout << endl;
    return 0;
}