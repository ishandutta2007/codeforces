// ./e-paint-it-really-really-dark-gray.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 2e5 + 1;
int N,
    A[MN];
vector<int> g[MN];

void dfs(int c, int p) {
    cout << c << ' ';
    for (auto to : g[c]) {
        if (to != p) {
            dfs(to, c);
            cout << c << ' ';
            if (A[to]) {
                A[to] ^= 1;
                A[c] ^= 1;
                cout << to << ' ' << c << ' ';
            }
        }
    }
    A[c] ^= g[c].size() & 1; // SZ(adj) for v=1, SZ(adj)-1+1 for v!=1
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (auto i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] = (1 - A[i]) / 2;
    }
    for (auto i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    if (A[1]) {
        int u = g[1][0];
        cout << u << " 1 " << u;
    }
    cout << '\n';

    return 0;
}