#include <bits/stdc++.h>
#define fr first
#define sc second
#define m_p make_pair
using namespace std;

typedef long long ll;

const ll llinf = 1e18;

const int maxn = 1e5 + 100, inf = 1e9 + 100;

int n;

ll a[maxn];

ll b[maxn];

int main() {
    #ifdef ONPC
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++)
        a[i] = a[i + 1] - a[i] - 1;
    n--;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        b[i + 1] = b[i] + a[i];
    int zap;
    cin >> zap;
    while (zap--) {
        ll L, R;
        cin >> L >> R;
        ll x = R - L;
        int l = 0, r = n + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (a[m - 1] <= x)
                l = m;
            else
                r = m;
        }
        cout << x * (n - l) + x + n + 1 + b[l] << ' ';
    }
}