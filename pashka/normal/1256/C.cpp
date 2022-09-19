#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    int s = n;
    for (int i = 0; i < m; i++) s -= a[i];

    if ((d - 1) * (m + 1) < s) {
        cout << "NO\n";
        return 0;
    }

    vector<int> u(m);
    for (int i = 0; i < m; i++) {
        u[i] = s / (m + 1);
    }
    for (int i = 0; i < s % (m + 1); i++) {
        u[i]++;
    }

    vector<int> res(n);
    int k = 0;
    for (int i = 0; i < m; i++) {
        k += u[i];
        for (int j = 0; j < a[i]; j++) {
            res[k++] = i + 1;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";


    return 0;
}