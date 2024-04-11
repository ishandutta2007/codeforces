#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define inf INFINITY
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int flag = 1;
        if (a[0] < 0) flag = 0;

        a.push_back(-a[n-1]);

        ll m = a[0], ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] * (ll)a[i-1] < 0) {
                flag = 1 - flag;
                ans += m;
                m = a[i];
                continue;
            }
            m = max(m, a[i]);
        }

        cout << ans << "\n";
    }

    return 0;
}