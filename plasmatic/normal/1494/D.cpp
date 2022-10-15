// ./d-dogeforces.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 501;
int N,
    A[MN][MN], S[MN*2];

int ctr = 0;
vector<pair<int, int>> edges;
int solve(vector<int> v) {
    if ((int)v.size() == 1) {
        S[v[0]] = A[v[0]][v[0]];
        return v[0];
    }

    int n = ctr++, mxs = 0;
    for (auto x : v)
        for (auto y : v)
            mxs = max(mxs, A[x][y]);
    S[n] = mxs;

    bool vis[MN]; memset(vis, false, sizeof vis);
    function<void(int, vector<int>&)> dfs = [&] (int c, vector<int> &comp) {
        if (vis[c]) return;
        vis[c] = true;
        comp.push_back(c);
        for (auto to : v)
            if (A[c][to] != mxs)
                dfs(to, comp);
    };
    for (auto x : v) {
        if (!vis[x]) {
            vector<int> cur;
            dfs(x, cur);
            edges.emplace_back(solve(cur), n);
        }
    }

    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    ctr = N;
    for (auto i = 0; i < N; i++)
        for (auto j = 0; j < N; j++)
            cin >> A[i][j];

    vector<int> v(N); iota(v.begin(), v.end(), 0);
    int rt = solve(v);
    cout << (ctr) << '\n';
    for (auto i = 0; i < ctr; i++) cout << S[i] << ' ';
    cout << '\n' << (rt+1) << '\n';
    for (auto p : edges)
        cout << (p.first+1) << ' ' << (p.second+1) << '\n';

    return 0;
}