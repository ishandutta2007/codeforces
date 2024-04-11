/**
 * For update(v, d), it is the same as iterating through c, c is subtree
 * of v, such that EV(!c) += d * size(c) / N.
 * 
 * It is equal to EV(c) += d * size(!c) / N = d * (N - size(c) - 1) / N.
 * 
 * We will consider r == v separately, by keeping a global EV. This global
 * EV can also be used to update every other node except the current subtree
 * when we root it and use euler tour.
 * 
 * We will also sort the adjacency list, and can update multiple subtrees
 * with the same size with one huge range update. Notice that the number
 * of unique subtree sizes will not exceed O(sqrt(n)).
 * 
 * The total time complexity is O(n sqrt(n) log(n)).
 * 
**/

#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MOD = 998244353;

int inverse(int n, int m = MOD) {
    int u = 0, v = 1;
    while (n != 0) {
        int q = m / n;
        m -= q * n; swap(n, m);
        u -= q * v; swap(u, v);
    }
    assert(m == 1);
    return u;
}

int N, Q, INVERSE;
vector<int> G[150005];
int SZ[150005];
pair<int, int> T[150005];
vector<pair<pair<int, int>, int>> intervals[150005]; // collection of unique sizes
lint EXTRA_EV[150005];

void dfsSZ(int n, int p = -1) { // get subtree size
    SZ[n] = 1;
    for (auto i : G[n]) if (i != p) {
        dfsSZ(i, n);
        SZ[n] += SZ[i];
    }
}

void dfsET(int n, int p = -1) { // euler tour on tree
    static int t = 1;
    T[n].first = t++;
    
    for (int i = 0; i < G[n].size(); i++) {
        if (G[n][i] == p) {
            swap(G[n][i], G[n][G[n].size() - 1]);
            G[n].pop_back();
            break;
        }
    }

    sort(G[n].begin(), G[n].end(), [&](int i, int j) {
        return SZ[i] < SZ[j];
    });

    for (auto i : G[n]) if (i != p) {
        dfsET(i, n);
    }

    for (auto i : G[n]) if (i != p) {
        if (intervals[n].size() > 0 && intervals[n].back().second == SZ[i]) {
            intervals[n].back().first.second = T[i].second;
        } else {
            intervals[n].emplace_back(T[i], SZ[i]);
        }
    }

    T[n].second = t - 1;
}

struct BIT {
    lint bit[150005] = {};

    void update(int n, int m, lint x) {
        if (x < 0) x += MOD;
        for (int i = n; i < 150005; i += (i & -i)) {
            bit[i] += x;
        }
        for (int i = m + 1; i < 150005; i += (i & -i)) {
            bit[i] -= x;
        }
    }

    lint query(int n, lint res = 0) {
        for (int i = n; i > 0; i -= (i & -i)) {
            res += bit[i];
        }
        return res;
    }

} bit;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

    cin >> N >> Q;

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int root = (((rng() % N) + N) % N) + 1;
    dfsSZ(root);
    dfsET(root);

    INVERSE = (inverse(N) % MOD + MOD) % MOD;
    
    for (int i = 0; i < Q; i++) {
        int t = 0, v = 0;
        cin >> t >> v;
        if (t == 1) {
            int d;
            cin >> d;
            for (auto j : intervals[v]) {
                bit.update(j.first.first, j.first.second, 1ll * d * (N - j.second));
            }
            bit.update(1, N, (1ll * d * SZ[v]) % MOD);
            bit.update(T[v].first, T[v].second,  -(1ll * d * SZ[v]));
            EXTRA_EV[v] += (1ll * N * d);

        } else if (t == 2) {
            cout << ((((EXTRA_EV[v] + bit.query(T[v].first)) % MOD) * INVERSE) % MOD + MOD) % MOD << "\n";
        }
    }
    return 0;
}