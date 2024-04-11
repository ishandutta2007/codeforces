#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    map<int, int> val;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        val[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    if (val.size() <= 2) {
        cout << n << endl;
        return 0;
    }
    int res = 0;
    for (auto u : val) {
        bitset<N * N> b[N];
        b[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == u.first) continue;
            for (int j = u.second; j; j--) {
                b[j] = b[j] | (b[j - 1] << a[i]);
            }
        }
        int f = -1;
        for (int i = 1; i <= u.second; i++) {
            if (u.first * i >= N * N) break;
            if (b[i][u.first * i]) {
                f = i;
                break;
            }
        }
        if (f == -1) res = max(res, u.second);
        else res = max(res, f - 1);
    }
    cout << res << endl;
    return 0;
}