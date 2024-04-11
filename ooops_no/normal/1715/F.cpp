#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

ld ask(vector<pair<ld, ld>> p) {
    cout << "? " << p.size() << endl;
    for (auto to : p) {
        cout << setprecision(15) << fixed << to.first << ' ' << to.second << endl;
    }
    ld x;
    cin >> x;
    return x;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<ld, ld>> p{{-1, -0.5}, {-1, 100.5}, {100, 100}};
    for (int i = 99; i >= 0; i--) {
        p.pb({0, i + 0.5});
        p.pb({100, i});
    }
    ld x = ask(p);
    for (int i = 0; i < p.size(); i++) {
        swap(p[i].first, p[i].second);
    }
    ld y = ask(p);
    cout << "! " << setprecision(15) << fixed << (100 - x * 100) - 0.5 << ' ' << (100 - y * 100) - 0.5 << endl;
    return 0;
}