#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vi a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        int dp[n + 1];
        fill(dp, dp + n + 1, 1);

        for (int i = n; i >= 1; i--) {
            for (int j = i + i; j <= n; j += i) {
                if (a[i] < a[j])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        cout << *max_element(dp, dp + n + 1) << "\n";
    }
    return 0;
}