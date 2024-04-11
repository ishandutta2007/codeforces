#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int LOG = 31;

int n;
int num[2][LOG];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < LOG; i++) num[0][i] = num[1][i] = 0;
        for (int i = 1; i <= n; i++) {
            int u;
            cin >> u;
            for (int j = 0; j < LOG; j++) {
                if (u >> j & 1) {
                    num[1][j]++;
                } else {
                    num[0][j]++;
                }
            }
        }
        int found = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            if (num[1][i] % 2 == 0) {
                continue;
            }
            if (num[1][i] % 4 == 1) {
                cout << "WIN\n";
                found = 1;
                break;
            }
            if (num[0][i] % 2 == 0) {
                cout << "LOSE\n";
            } else {
                cout << "WIN\n";
            }
            found = 1;
            break;
        }
        if (!found) {
            cout << "DRAW\n";
        }
    }
    return 0;
}