#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m, d;
    cin >> n >> m >> d;
    int A[m + m] = {};
    int ans[n + n] = {};
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        cin >> A[i];
        sum += A[i];
    }
    int opt = ceil((double)(n - sum) / (m + 1));
    if (opt >= d) {
        cout << "NO\n";
        return 0;
    }
    
    sum = n - sum;
    for (int i = 1, ptr = 1; i <= n; i++) {
        if (sum > 0) {
            i += min(sum, d - 1);
            sum -= min(sum, d - 1);
        }
        while (A[ptr]--) {
            if (ptr > m) break;
            ans[i++] = ptr;
        }
        ptr++;
        i--;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}