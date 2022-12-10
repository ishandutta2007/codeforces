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
    int n, m;
    cin >> n >> m;
    int k[n];
    for (int i = 0; i < n; i++)
        cin >> k[i], k[i]--;
    LL c[m];
    for (int i = 0; i < m; i++)
        cin >> c[i];
    int ord[n];
    iota(ord, ord + n, 0);
    sort(ord, ord + n, [&](int i, int j) {return k[i] > k[j]; });
    LL ans = 0;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        int id = k[ord[i]];
        if (pos > id)
            ans += c[id];
        else {
            ans += c[pos];
            pos++;
        }
    }
    cout << ans << '\n';
    return 0;
}