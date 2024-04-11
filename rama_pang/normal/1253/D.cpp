#include <bits/stdc++.h>
#define debug(x) cerr << ">>>> " << #x << " is " << x << endl
#define testcase int TESTCASE; cin >> TESTCASE; while (TESTCASE--)
using namespace std;
using lint = long long;
using loat = long double;

const lint MOD = (lint)1e9 + 7;
const loat PI = cos((loat)-1);

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int p[400005];

int par(int n) {
    return (p[n] == n)? n : p[n] = par(p[n]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;
    int comp = N;
    iota(p, p + N + 5, 0);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        if (par(u) == par(v)) continue;
        p[par(u)] = par(v);
    }

    map<int, pair<int, int>> mp;
    for (int i = 1; i <= N; i++) {
        if (mp.find(par(i)) == mp.end()) {
            mp[par(i)].first = i;
            mp[par(i)].second = i;
        }
        mp[par(i)].first = min(mp[par(i)].first, i);
        mp[par(i)].second = max(mp[par(i)].second, i);
    }

    int ans = 0;
    // cout << mp[par(1)].first << " " << mp[par(1)].second << "\n";
    for (int i = 1; i <= N; i++) {
        for (int j = mp[par(i)].first; j <= mp[par(i)].second; j++) {
            if (par(i) == par(j)) continue;
            // cout << i << " " << j << "\n";
            ans++;
            mp[par(i)].second = max(mp[par(i)].second, mp[par(j)].second);
            p[par(j)] = par(i);
            
        }

        mp[par(i)].first = mp[par(i)].second;
    }

    cout << ans << "\n";
    return 0;
}