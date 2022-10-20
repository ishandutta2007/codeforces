#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n;
int a[N], b[N];
long long c[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int g = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x] = b[x] = 1;
        g = __gcd(g, x);
    }
    if (g > 1) {
        cout << -1 << endl;
        return 0;
    }
    int res = 1;
    while (!b[1]) {
        res++;
        memset(c, 0, sizeof c);
        for (int i = N - 1; i > 0; i--) {
            int aa = 0, bb = 0;
            for (int j = i; j < N; j += i) {
                aa += a[j];
                bb += b[j];
                c[i] -= c[j];
            }
            c[i] += 1ll * aa * bb;
        }
        for (int i = 0; i < N; i++) {
            b[i] = (c[i] != 0);
        }
    }
    cout << res << endl;
    return 0;
}