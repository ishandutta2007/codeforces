#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int n, m;
vector<int> x, y;
vector<int> a;
vector<bool> z;
int res;

void bt(int i) {
    if (i == n) {
        vector<vector<bool>> q(6, vector<bool>(6));
        int s = 0;
        for (int j = 0; j < m; j++) {
            if (!q[a[x[j]]][a[y[j]]]) {
                s++;
                q[a[x[j]]][a[y[j]]] = true;
                q[a[y[j]]][a[x[j]]] = true;
            }
        }
        res = max(res, s);
        return;
    }
    bool first = true;
    for (int j = 0; j < 6; j++) {
        if (z[j]) {
            a[i] = j;
            bt(i + 1);
        } else {
            if (first) {
                first = false;
                z[j] = true;
                a[i] = j;
                bt(i + 1);
                z[j] = false;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    x.resize(m);
    y.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }
    z.resize(6);
    a.resize(n);
    bt(0);

    cout << res << "\n";

    return 0;
}