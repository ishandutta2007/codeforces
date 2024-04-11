//
// Created by Ormlis (t.me/averageCFenjoyer) on 20.03.2022.
//

#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef long double ld;

using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;

const int INFi = 2e9;
const ll INF = 2e18;
const int LG = 20;
const int C = 400;
const int B = 300;
const int maxN = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = (1 << n);
    vi ind(m);
    rep(i, m) ind[i] = s[i] - 'a';
    for (int k = 2, b = 1; k <= m; k *= 2, b *= 2) {
        vector<pair<int, int>> kek;
        for (int i = 0; i < m; i += k) {
            rep(x, b) {
                kek.emplace_back(ind[i + x], ind[i + b + x]);
                kek.emplace_back(ind[i + b + x], ind[i + x]);
            }
        }
        sort(all(kek));
        vi nxt(m);
        kek.resize(unique(all(kek)) - kek.begin());
        for (int i = 0; i < m; i += k) {
            rep(x, b) {
                nxt[i + x] = lower_bound(all(kek), make_pair(ind[i + x], ind[i + b + x])) -
                             kek.begin();
                nxt[i + x + b] = lower_bound(all(kek), make_pair(ind[i + b + x], ind[i + x])) -
                                 kek.begin();
            }
        }
        swap(nxt, ind);
    }
    int mn = min_element(all(ind)) - ind.begin();
    rep(i, m) cout << s[i^mn];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}