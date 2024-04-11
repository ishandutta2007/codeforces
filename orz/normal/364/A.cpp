#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

int cnt[100007];
int rid[100007];
int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
    map<int, int> ids;
    vector<pair<int, int> > dv;

    int x;
    cin >> x;
    if (x != 0) {
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                int id = ids.size();
                int id2 = id;
                ids[i] = id;
                rid[id] = x;
                if (x / i != i) {
                    id2 = ids.size();
                    ids[x / i] = id2;
                    rid[id2] = x / i;
                }
                dv.emplace_back(id, id2);
            }
        }
    } else {
        ids[0] = 0;
        dv.emplace_back(0, 0);
    }

    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int sm = 0;
        for (int j = i; j < n; j++) {
            sm += s[j] - '0';
            if (sm != 0 && x != 0 && x % sm == 0) {
                cnt[ids[sm]]++;
            } else if (sm == 0 && ids.count(0)) {
                cnt[ids[0]]++;
            }
        }
    }

    if (x == 0) {
        int z = cnt[0];
        int tot = n * (n + 1) / 2;
        cout << 1ll * tot * tot - 1ll * (tot - z) * (tot - z) << "\n";
        return 0;
    }
    ll ans = 0;
    for (const auto& pr : dv) {
        int x = pr.first, y = pr.second;
        ans += 1ll * cnt[x] * cnt[y];
        if (x != y) {
            ans += 1ll * cnt[x] * cnt[y];
        }
    }

    cout << ans << "\n";
    return 0;
}