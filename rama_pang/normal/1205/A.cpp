#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "NO\n";
        return 0;
    }

    vector<int> ans(2 * n, -1);
    int cur = 0, cnt = 0;
    while (ans[cur] == -1) {
        ans[cur] = cnt++;
        cur = (cur + n) % (2 * n);
        ans[cur] = cnt++;
        cur++;
        cur %= 2 * n;
    }

    cout << "YES\n";
    for (int i = 0; i < 2 * n; i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";

    return 0;
}