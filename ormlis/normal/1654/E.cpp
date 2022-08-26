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
const int maxN = 1e5 + 10;

int cnt[(C + 2) * maxN * 2];

void solve() {
    int mid = (C + 2) * maxN;
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int ans = 1;
    rep(_, 2) {
        for (int k = 0; k < C; ++k) {
            rep(i, n) {
                int v = a[i] - i * k;
                cnt[v + mid]++;
                ans = max(ans, cnt[v + mid]);
            }
            rep(i, n) {
                cnt[a[i] - i * k + mid]--;
            }
        }
        rep(i, n) {
            for (int j = max(0, i - B); j < i; ++j) {
                int v = a[i] - a[j];
                if (v >= 0 && v % (i - j) == 0) {
                    int w = v / (i - j);
                    cnt[w]++;
                    ans = max(ans, cnt[w] + 1);
                }
            }
            for (int j = max(0, i - B); j < i; ++j) {
                int v = a[i] - a[j];
                if (v >= 0 && v % (i - j) == 0) {
                    int w = v / (i - j);
                    cnt[w]--;
                }
            }
        }
        reverse(all(a));
    }
    cout << n - ans << '\n';
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