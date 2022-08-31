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
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(all(a));

        int ans = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            cur += 1;
            if (cur == a[i]) {
                ans += 1;
                cur = 0;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}