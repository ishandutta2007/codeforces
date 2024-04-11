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
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    map<ll, int> cnt;
    for (auto &x : a) cnt[x]++;
    ll sum = accumulate(all(a), 0ll);
    queue<ll> q;
    q.push(sum);
    int need = n;
    while (!q.empty()) {
        if ((int) q.size() > need) {
            cout << "NO\n";
            return;
        }
        ll x = q.front();
        q.pop();
        if (cnt[x] == 0) {
            if (x == 1) {
                cout << "NO\n";
                return;
            }
            q.push(x / 2);
            q.push(x - x / 2);
            continue;
        }
        cnt[x]--;
        need--;
    }
    cout << "YES\n";
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