#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
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
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, ar<char, 2>> mp;
    int t1 = 0, t2 =0;
    range(_, m) {
        char x;
        cin >> x;
        if (x == '+') {
            int u, v;
            char c;
            cin >> u >> v >> c;
            int k = 0;
            if (u > v) {
                swap(u, v);
                k = 1;
            }
            mp[{u, v}][k] = c;
            if (mp[{u, v}][k ^ 1] != 0) {
                t1++;
            }
            if (mp[{u, v}][k ^ 1] == c) {
                t2++;
            }
        } else if (x == '-') {
            int u, v;
            cin >> u >> v;
            int k = 0;
            if (u > v) {
                swap(u, v);
                k = 1;
            }
            if (mp[{u, v}][k ^ 1] != 0) {
                t1--;
            }
            if (mp[{u, v}][k ^ 1] == mp[{u, v}][k]) {
                t2--;
            }
            mp[{u, v}][k] = 0;
        } else {
            int k; cin >> k;
            if (!t1) {
                cout << "NO\n";
                continue;
            }
            if (k % 2 == 1) {
                cout << "YES\n";
                continue;
            }
            if (t2) {
                cout << "YES\n";
                continue;
            }
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}