#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int best = 1;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i <= k)
                    best = max(best, i);
                if (i != n / i and n / i <= k)
                    best = max(best, n / i);
            }
        }
        cout << n / best << "\n";
    }
    return 0;
}