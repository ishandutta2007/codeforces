#include <iostream>
#include <algorithm>

using namespace std;
const int N = 5e3 + 10;
const int MAX = 1e7 + 10;

int a[N];
bool have[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    int k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        have[a[i]] = true;
    }
    int q;
    cin >> q;
    for (int q_cur = 1; q_cur <= q; q_cur++) {
        int sum;
        cin >> sum;
        int ans = N;
        for (int i = 1; i <= n; i++) {
            for (int c1 = 0; c1 <= k; c1++) {
                for (int c2 = 0; c1 + c2 <= k; c2++) {
                    if (c1 * a[i] > sum) {
                        continue;
                    }
                    int leave = sum - c1 * a[i];
                    if (leave == 0) {
                        ans = min(ans, c1);
                        continue;
                    }
                    if (c2 == 0) {
                        continue;
                    }
                    if (leave % c2 != 0) {
                        continue;
                    }
                    int need = leave / c2;
                    if (need >= MAX) {
                        continue;
                    }
                    if (!have[need]) {
                        continue;
                    }
                    ans = min(ans, c1 + c2);
                }
            }
        }
        if (ans == N) {
            ans = -1;
        }
        cout << ans << "\n";
    }
    return 0;
}