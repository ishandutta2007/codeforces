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
const int maxN = 1e5;

void solve() {
    string s; cin >> s;
    vector<int> last(26, (int)s.size());
    rep(i, (int)s.size()) {
        last[s[i] - 'a'] = i;
    }
    cout << s.substr(*min_element(all(last)), s.size()) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}