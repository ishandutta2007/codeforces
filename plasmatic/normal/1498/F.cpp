// ./f-christmas-game.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e5 + 1, MK = 21;
int N, K,
    A[MN];
vector<int> g[MN];

int dn[MN][MK*2], up[MN][MK*2];

void incDepth(int a[MK*2]) {
    static int tmp[MK*2];
    for (auto i = 0; i < 2*K; i++) tmp[(i+1)%(2*K)] = a[i];
    copy(tmp, tmp+2*K, a);
}
void combine(int a[MK*2], int from[MK*2]) { for (auto i = 0; i < 2*K; i++) a[i] ^= from[i]; }

void dfs(int c, int p) {
    for (auto to : g[c]) {
        if (to != p) {
            dfs(to, c);
            for (auto i = 0; i < 2*K; i++)
                dn[c][i] ^= dn[to][i];
        }
    }
    incDepth(dn[c]);
    dn[c][0] ^= A[c];
}

void dfs2(int c, int p) {
    // combine parent
    int tmp[MK*2]; copy(up[c], up[c]+K*2, tmp);
    // combine children
    for (auto to : g[c]) {
        if (to != p) {
            int ttmp[MK*2]; copy(dn[to], dn[to]+K*2, ttmp);
            incDepth(ttmp);
            combine(tmp, ttmp);
        }
    }
    tmp[0] ^= A[c];
    // properly set depth
    incDepth(tmp);
    for (auto to : g[c]) {
        if (to != p) {
            copy(dn[to], dn[to]+K*2, up[to]);
            incDepth(up[to]); incDepth(up[to]);
            combine(up[to], tmp); // reverse the addition because we need to propagate this further

            // visit children
            dfs2(to, c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (auto i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (auto i = 1; i <= N; i++) 
        cin >> A[i];
    dfs(1, -1);
    dfs2(1, -1);

    for (auto i = 1; i <= N; i++) {
        int ans = 0;
        for (auto j = K; j < 2*K; j++) ans ^= up[i][j] ^ dn[i][j];
        cout << (ans > 0) << ' ';
    }
    cout << '\n';

    return 0;
}