#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int n, m;
int res[N];
int num[5000010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int cur = 1;
    for (int i = 1; i <= n; i++) {
        if (m == 0) {
            res[i] = 1000000000 - (n - i) * cur;
            continue;
        }
        while (num[cur] > m) cur++;
        res[i] = cur;
        m -= num[cur];
        for (int j = 1; j < i; j++) {
            num[res[i] + res[j]]++;
        }
        cur++;
    }
    if (m > 0) {
        cout << -1 << endl;
    } else {
        for (int i = 1; i <= n; i++) cout << res[i] << ' ';
            cout << endl;
    }
    return 0;
}