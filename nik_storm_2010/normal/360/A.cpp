#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;
const int N = 5000 + 10;

int a[N], sum[N], t[N], l[N], r[N], z[N];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i] = 2e9;
    for (int i = 1; i <= m; i++) {
        cin >> t[i] >> l[i] >> r[i] >> z[i];
        if (t[i] == 1)
        for (int j = l[i]; j <= r[i]; j++) sum[j] += z[i];
        else
        for (int j = l[i]; j <= r[i]; j++) a[j] = min(a[j], z[i] - sum[j]);
    }
    for (int i = 1; i <= n; i++) if (a[i] == 2e9) a[i] = 0;
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= m; i++) {
        if (t[i] == 1)
        for (int j = l[i]; j <= r[i]; j++) sum[j] += z[i];
        else {
            int res = -2e9;
            for (int j = l[i]; j <= r[i]; j++) res = max(res, a[j] + sum[j]);
            if (res != z[i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}