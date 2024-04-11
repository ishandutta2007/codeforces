#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n;
char a[N];

int get(int u, char v) {
    u = (a[u] - 'A');
    int vv = v - 'A';
    return min((u - vv + 26) % 26, (vv - u + 26) % 26);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> (a + 1);
    int res = 1e9;
    for (int i = 1; i + 3 <= n; i++) {
        res = min(res, get(i, 'A') + get(i + 1, 'C') + get(i + 2, 'T') + get(i + 3, 'G'));
    }
    cout << res << endl;
    return 0;
}