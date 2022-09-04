#include <bits/stdc++.h>
#define fr first
#define sc second
#define m_p make_pair
using namespace std;

typedef long long ll;

const ll llinf = 1e18;

const int maxn = 3e5 + 100, inf = 1e9 + 100;

int n;

int main() {
    #ifdef ONPC
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll sum = 0, s = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sum += x;
        ll o = min(x / 2, s);
        x -= 2 * o;
        s -= o;
        s += x % 3;
    }
    cout << (sum - s) / 3;
}