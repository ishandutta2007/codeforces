#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int m;
        cin >> m;

        int n = 32 - __builtin_clz(m);

        vector<int> p(m);
        for (auto &x : p) cin >> x, --x;

        int answer = 0;
        while (m > 1) {
            bool possible = true;
            for (int i = 0; i < m; i += 2) {
                if (p[i] > p[i + 1]) {
                    swap(p[i], p[i + 1]);
                    answer += 1;
                }
                possible &= p[i] % 2 == 0 && p[i + 1] == 1 + p[i];
            }

            if (!possible) {
                answer = -1;
                break;
            }

            m /= 2;
            for (int i = 0; i < m; i++) {
                p[i] = p[2 * i] / 2;
            }
        }

        cout << answer << '\n';
    }
    return 0;
}