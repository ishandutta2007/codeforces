#include <bits/stdc++.h>
using namespace std;

void solve() {
    int nbApps;
    cin >> nbApps;
    vector<int> type(nbApps);
    for (int &t : type)
        cin >> t;
    vector<int> occ;
    {
        map<int, int> m;
        for (int t : type)
            m[t]++;
        for (auto [t, c] : m)
            occ.push_back(c);
    }

    int M = nbApps;
    for (int c : occ)
        M = min(M, c + 1);
    int sol = 1e9;
    for (int s = 1; s <= M; ++s) {
        int m = 0;
        bool ok = true;
        for (int x : occ) {
            int b = x% s;
            if (b)
                b = s - b;
            int a = (x + b) / s;
            if (a >= b)
                m += a;
            else {
                ok = false;
                break;
            }
        }
        if (ok)
            sol = min(sol, m);
    }
    cout << sol << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--)
        solve();
}