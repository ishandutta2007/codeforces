#ifdef ONPC
    #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char
 
using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
 
typedef long long ll;
typedef long double ld;
 
int solve() {
    int n, m;
    if (!(cin >> n >> m)) {
        return 1;
    }
    vector<int> bigneighbours(n, 0);
    int cntup = 0;
    auto link = [&] (int v, int u) {
        if (v > u) {
            swap(v, u);
        }
        if (bigneighbours[v] == 0) {
            cntup++;
        }
        bigneighbours[v]++;
    };
    auto cut = [&] (int v, int u) {
        if (v > u) {
            swap(v, u);
        }
        if (bigneighbours[v] == 1) {
            cntup--;
        }
        bigneighbours[v]--;
    };
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        link(v, u);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 3) {
            cout << n - cntup << '\n';
        } else {
            int v, u;
            cin >> v >> u;
            v--;
            u--;
            if (type == 1) {
                link(v, u);
            } else {
                cut(v, u);
            }
        }
    }
    return 0;
}
 
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1e9;
    //cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}