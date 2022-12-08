#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, u;
    cin >> n >> u;


    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }


    int k = 0;

    double ans = -1e18;

    for (int i = 0; i < n; i++) {
        while (k < n && A[i] + u >= A[k]) k++;
        k--;

        if (i + 1 >= k) continue;
        int j = i + 1;

        //err("i = %d, j = %d, k = %d\n", i, j, k);

        double cur = 1 + (A[i] - A[j]) * 1.0 / (A[k] - A[i]);
        if (cur > ans) ans = cur;
    }

    if (ans < -10) return 0 * puts("-1");
    cout.precision(10);
    cout << fixed << ans << "\n";
    return 0;
}