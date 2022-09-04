#include <bits/stdc++.h>
#define fr first
#define sc second
#define m_p make_pair
using namespace std;

typedef long long ll;

const ll llinf = 1e18;

const int maxn = 1e6 + 100, inf = 1e9 + 100;

int main() {
    #ifdef ONPC
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    if (a[i] != a[0]) {
        ans = i;
        break;
    }
    for (int i = 0; i < n; i++)
    if (a[i] != a[n - 1]) {
        ans = max(ans, n - 1 - i);
        break;
    }
    cout << ans;
}