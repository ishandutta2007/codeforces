#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;

const int INFi = 2e9 + 5;
const int maxN = 3e5 + 100;
const int md = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    int n; cin >> n;
    vector<ar<int, 3>> a(n);
    range(i, n) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    set<pair<ll, ll>> has;
    has.insert({0, a[0][0] + a[0][1]});
    sort(all(a));
    ll dmx;
    {
        vector<ll> dist(n, INF);
        ll k = -INF;
        for(int i = 0; i < n; ++i) {
            while(!has.empty()) {
                auto [c, d] = *has.begin();
                if (d < a[i][0]) {
                    k = max(k, d - c);
                    has.erase(has.begin());
                    continue;
                }
                dist[i] = c;
                break;
            }
            dist[i] = min(dist[i], a[i][0] - k);
            has.insert({dist[i], a[i][0] + a[i][1]});
        }
        dmx = dist[n - 1];
    }
    ll dmn;
    ll answer;
    {
        has.clear();
        has.insert({0, a[0][0] + a[0][1]});
        vector<ll> dist(n, INF);
        ll k = -INF;
        dist[0] = 0;
        for(int i = 0; i < n; ++i) {
            while(!has.empty()) {
                auto [c, d] = *has.begin();
                if (d < a[i][0]) {
                    k = max(k, d - c);
                    has.erase(has.begin());
                    continue;
                }
                dist[i] = c;
                break;
            }
            dist[i] = min(dist[i], a[i][0] - k);
            has.insert({dist[i], a[i][0] + a[i][1]});
            if (a[i][2] == 0) {
                dmn = dist[i];
            }
        }
        answer = min(dist[n - 1], dmn + dmx);
    }
    range(i, n) answer += a[i][1];
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}