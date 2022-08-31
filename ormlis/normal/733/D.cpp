#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
//using namespace __gnu_pbds;

const int INFi = 2e9 + 5;
const int maxN = 2e3;
const int md = 998244353;
const ll INF = 2e18;

void solve() {
    int n; cin >> n;
    map<pair<int, int>, pair<int, int>> was;
    int answer = -1;
    int ans1 = -1, ans2 = -1;
    range(i, n) {
        int a, b, c; cin >> a >> b >> c;
        int x = min({a, b, c});
        if (x > answer) {
            answer = x;
            ans1 = i;
            ans2 = -1;
        }
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);
        int d = min({a, b, c + was[{a, b}].first});
        if (d > answer) {
            answer = d;
            ans1 = i;
            ans2 = was[{a, b}].second;
        }
        d = min({a, c, b + was[{a, c}].first});
        if (d > answer) {
            answer = d;
            ans1 = i;
            ans2 = was[{a, c}].second;
        }
        d = min({b, c, a + was[{b, c}].first});
        if (d > answer) {
            answer = d;
            ans1 = i;
            ans2 = was[{b, c}].second;
        }
        was[{a, b}] = max(was[{a, b}], {c, i});
        was[{a, c}] = max(was[{a, c}], {b, i});
        was[{b, c}] = max(was[{b, c}], {a, i});
    }
    if (ans2 == -1) {
        cout << "1\n";
        cout << ans1 + 1;
    } else {
        cout << "2\n";
        cout << ans1 + 1<< " " << ans2 + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}