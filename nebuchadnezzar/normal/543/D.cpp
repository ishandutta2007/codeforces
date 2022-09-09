#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 2e5 + 5;
const LL MOD = 1e9 + 7;

int n;
vector <int> graph[MAXN];
LL d[MAXN];
LL ans[MAXN];

int dfs1(int v) {
    LL now = 1;
    for (int i = 0; i < szof(graph[v]); ++i) {
        dfs1(graph[v][i]);
        now = (now * (d[graph[v][i]] + 1)) % MOD;
    }
    d[v] = now;
    //cerr << v << " " << d[v] << endl;
    return 0;
}

int dfs2(int v, LL up) {
    vector <LL> vec;
    for (int i = 0; i < szof(graph[v]); ++i) {
        vec.puba(d[graph[v][i]]);
    }
    vector <LL> pref, suff;
    pref.resize(szof(vec) + 1);
    pref[0] = 1;
    for (int i = 0; i < szof(vec); ++i) {
        pref[i + 1] = (pref[i] * (vec[i] + 1)) % MOD;
    }
    suff.resize(szof(vec) + 1);
    suff[szof(vec)] = 1;
    for (int i = szof(vec) - 1; i >= 0; --i) {
        suff[i] = (suff[i + 1] * (vec[i] + 1)) % MOD;
    }
    ans[v] = d[v] * (up + 1) % MOD;
    for (int i = 0; i < szof(graph[v]); ++i) {
        dfs2(graph[v][i], (up + 1) * pref[i] % MOD * suff[i + 1] % MOD);
    }
    return 0;
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int num;
        cin >> num;
        graph[num - 1].puba(i + 1);
    }

    dfs1(0);

    dfs2(0, 0);

    for (int i = 0; i < n; ++i) {
        cout << ans[i] % MOD << " ";
    }
    cout << endl;

    return 0;
}