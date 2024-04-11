#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lint = long long;

/*  Sort by minimum subtree height.
    That is optimal way of ordering.
    Euler tour on the tree with priority.
    Use operation (heightA - heighB) times
    on the same vertex.
*/

int N;
vector<int> G[200005];
int H[200005], Rank[200005], P[200005];
vector<int> ans, bamboo;

bool cmp(int a, int b) {
    return H[a] < H[b];
}

void dfs(int n) {
    int h = 0;
    for (auto v : G[n]) {
        dfs(v);
        h = max(h, H[v]);
    }
    H[n] = h + 1;
    sort(G[n].begin(), G[n].end(), cmp);
}

void tour(int n, int r = 1) {
    bamboo.push_back(n);
    Rank[n] = r;
    for (auto v : G[n]) tour(v, r + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 1; i < N; i++) {
        int pp; cin >> pp;
        G[pp].push_back(i);
    }
    dfs(0);
    tour(0);
    for (auto i : bamboo) cout << i << " ";
    cout << "\n";

    P[0] = -1;
    // iota(P, P + N, 0);
    for (int i = 1; i < bamboo.size(); i++) {
        P[bamboo[i]] = bamboo[i - 1];
    }
    for (int i = 1; i < bamboo.size(); i++) {
        while (P[bamboo[i]] > 0 && Rank[P[bamboo[i]]] >= Rank[bamboo[i]]) {
            ans.push_back(bamboo[i]);
            P[bamboo[i]] = P[P[bamboo[i]]];
        }
    }
    cout << ans.size() << "\n";
    for (auto i : ans) cout << i << " ";
    cout << "\n";
}