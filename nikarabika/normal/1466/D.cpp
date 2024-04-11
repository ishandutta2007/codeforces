//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}

int solve() {
    int n;
    cin >> n;
    int a[n], deg[n] = {0};
    LL ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i], ans += a[i];
    for (int i = 1; i < n; i++) {
        int fi, se;
        cin >> fi >> se;
        fi--, se--;
        deg[fi]++;
        deg[se]++;
    }
    multiset<int> s;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < deg[i]; j++)
            s.insert(-a[i]);
    for (int i = 1; i < n; i++) {
        cout << ans << ' ';
        ans -= *s.begin();
        if (sz(s))
        s.erase(s.begin());
    }
    cout << '\n';
    return 0;
}