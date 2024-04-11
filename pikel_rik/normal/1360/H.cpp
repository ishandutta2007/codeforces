#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 998244353;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            for (int j = 0; j < m; j++) {
                if (s[j] == '1')
                    a[i] |= (1ll << (m - j - 1));
            }
        }

        ll pos = (1ll << (m - 1)) - 1, total = (1ll << m) - 1;
        sort(all(a));

        ll ans = 0, c = 0;
        for (ll x : a)
            c += (x < pos - n - 1);

        for (ll i = pos - n; i <= pos + n; i++) {
            if (i < 0 or i > total) continue;
            bool flag = binary_search(all(a), i);

            c += (binary_search(all(a), i - 1));

            if (flag) continue;

            if (i - c + 1 == total - i - (n - c)) {
                ans = i;
                break;
            }
            else if (i - c == total - i - (n - c)) {
                ans = i;
                break;
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            if (ans & (1ll << i)) cout << '1';
            else cout << '0';
        }
        cout << "\n";
    }
    return 0;
}