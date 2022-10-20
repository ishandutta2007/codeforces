#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
long long a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i += 2) {
        cin >> a[i];
    }
    long long delta = 0;
    for (int i = 1; i <= n; i += 2) {
        int alpha = -1, beta = -1;
        for (int j = 1; j * j < a[i + 1]; j++) {
            if (a[i + 1] % j == 0) {
                int foo = a[i + 1] / j;
                if ((foo - j) % 2) continue;
                int bar = (foo - j) / 2;
                if (bar > delta) {
                    alpha = bar;
                    beta = (foo + j) / 2;
                }
            }   
        }
        if (beta == -1) {
            cout << "No" << endl;
            return 0;
        }
        a[i] = 1ll * beta * beta - 1ll * delta * delta - a[i + 1];
        delta = beta;
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}