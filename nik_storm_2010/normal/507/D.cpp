#include <iostream>

using namespace std;
const int N = 1000 + 10;
const int K = 100 + 10;

int f[N][K][2][2];

int main() {
    ios_base::sync_with_stdio(false);
    int n, k, m;
    cin >> n >> k >> m;
    f[0][0][0][0] = 1 % m;
    long long modifier = 1;
    for (int pref = 0; pref < n; pref++) {
        for (int mod = 0; mod < k; mod++) {
            for (int was = 0; was < 2; was++) {
                for (int not_zero = 0; not_zero <= 2; not_zero++) {
                    if (f[pref][mod][was][not_zero] == 0) {
                        continue;
                    }
                    for (int c = (pref + 1 == n ? 1 : 0); c <= 9; c++) {
                        int new_pref = pref + 1;
                        int new_mod = (mod + modifier * c) % k;
                        int new_was = was;
                        int new_not_zero = not_zero;
                        if (c != 0) {
                            new_not_zero = 1;
                        }
                        if (new_mod == 0 && new_not_zero) {
                            new_was = 1;
                        }
                        f[new_pref][new_mod][new_was][new_not_zero] += f[pref][mod][was][not_zero];
                        if (f[new_pref][new_mod][new_was][new_not_zero] >= m) {
                            f[new_pref][new_mod][new_was][new_not_zero] %= m;
                        }
                    }
                }
            }
        }
        modifier = (modifier * 10) % k;
    }
    int ans = 0;
    for (int mod = 0; mod < k; mod++) {
        ans = ans + f[n][mod][1][1];
        if (ans >= m) {
            ans -= m;
        }
    }
    cout << ans << "\n";
    return 0;
}