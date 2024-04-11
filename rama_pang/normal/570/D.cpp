#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int N, Q, par[2000005], timer = 1, depthmax = 0, D[2000005];
char A[2000005];
pair<int, int> et[2000005];
vector<int> G[2000005];
vector<pair<int, int>> H[2000005];
//store depth list of verteces
//euler tour, utk cek binser
//bikin prefix sum tiap depth
void dfs(int n, int depth) {
    et[n].fi = timer++;
    if (H[depth].size() == 0) H[depth].resize(1);
    H[depth].push_back(make_pair(timer, H[depth].back().se ^ (1ll << (A[n] - 'a'))));
    for (auto i : G[n]) {
        dfs(i, depth + 1);
    }
    et[n].se = timer++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    par[1] = -1;
    for (int i = 2; i <= N; i++) {
        cin >> par[i];
        G[par[i]].push_back(i);
    }
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    dfs(1, 1);
    // cout << "-===\n";
    // for (int i = 1; i <= depthmax; i++) {
    //     H[i] = H[i - 1];

    // }
    // for (int i = 1; i <= depthmax; i++) {
    //     for (int j = 0; j < H[i].size(); j++) {
    //         for (int k = 0; k <= 29; k++) {
    //             cout << H[i][j].alp[k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= Q; i++) {
        int v, h; cin >> v >> h;
        int l = lower_bound(H[h].begin(), H[h].end(), make_pair(et[v].fi, -1)) - H[h].begin() - 1;
        int r = lower_bound(H[h].begin(), H[h].end(), make_pair(et[v].se, -1)) - H[h].begin() - 1;
        int b = ((l < 0)? 0 : H[h][l].se) ^ ((r < 0)? 0 : H[h][r].se);
        // bitset<30> q(b); cout << q << endl;
        if (__builtin_popcount(b) > 1) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }

        // query(v, h);
        // cout << query(v, h) << "\n";
    }
}