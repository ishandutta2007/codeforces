#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), v(n);
    map<pair<int, int>, int> kek;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i].fi >> v[i].se;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ++kek[{a[j].fi + v[i].fi, a[j].se + v[i].se}];
        }
    }
    for (auto p : kek) {
        if (p.se == n) {
            cout << p.fi.fi << ' ' << p.fi.se;
            return 0;
        }
    }
    return 0;
}