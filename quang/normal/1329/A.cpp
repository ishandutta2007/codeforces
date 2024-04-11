#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int a[N];
int l[N], r[N];
int minVal, pos;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    reverse(a + 1, a + m + 1);
    minVal = 1e9;
    pos = 0;
    for (int i = 1; i <= m; i++) {
        if (i == 1) {
            l[i] = 1;
            r[i] = a[i];
        } else {
            r[i] = r[i - 1] + 1;
            l[i] = r[i] - a[i] + 1;
        }
        if (minVal > l[i]) {
            minVal = l[i];
            pos = i;
        }
    }
    for (int i = 1; i <= m; i++) {
        l[i] = l[i] - minVal + 1;
        r[i] = r[i] - minVal + 1;
    }
    if (r[m] > n) {
        cout << -1 << endl;
        return 0;
    }
    int maxVal = n;
    for (int i = m; i; i--) {
        if (r[i] >= maxVal) {
            maxVal = 0;
            break;
        }
        if (i == pos) continue;
        int delta = maxVal - r[i];
        r[i] += delta;
        l[i] += delta;
        maxVal = l[i] - 1;
    }
    if (maxVal > 0) {
        cout << -1 << endl;
        return 0;
    }
    reverse(l + 1, l + m + 1);
    for (int i = 1; i <= m; i++) {
        cout << l[i] << ' ';
    }
    cout << endl;
    return 0;
}