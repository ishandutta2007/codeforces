#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 100010;

int n, k;
int a[N];
int sum[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        
        sum[0] = 0;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + (a[i] < k);
        }

        if (n == 1) {
            cout << (a[1] == k ? "yes" : "no") << '\n';
            continue;
        }

        int has = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == k) {
                has = 1;
                break;
            }
        }

        if (!has) {
            cout << "no\n";
            continue;
        }

        int found = 0;
        int maxVal = -INF;
        for (int i = 1; i <= n; i++) {
            if (i > 1) maxVal = max(maxVal, 2 * sum[i - 2] - (i - 2));
            if (2 * sum[i] - i < maxVal) {
                found = 1;
                break;
            }
        }

        cout << (found ? "yes" : "no") << '\n';
    }   
    return 0;
}