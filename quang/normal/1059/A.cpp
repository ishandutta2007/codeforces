#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, L, a;
int t[N], l[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> L >> a;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> l[i];
    }
    int res = 0;
    res += t[1] / a;
    for (int i = 1; i < n; i++) {
        res += (t[i + 1] - t[i] - l[i]) / a;
    }
    res += (L - t[n] - l[n]) / a;
    cout << res << endl;
    return 0;
}