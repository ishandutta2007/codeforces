#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lint = long long;
int ans[305][305];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    int cur = 1;
    for (int j = 1; j <= n; j++) {
        if (j & 1) {
            for (int i = 1; i <= n; i++) {
                ans[i][j] = cur++;
            }
        } else {
            for (int i = n; i >= 1; i--) {
                ans[i][j] = cur++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
/*
1 6 7
2 5 8
3 4 9

*/