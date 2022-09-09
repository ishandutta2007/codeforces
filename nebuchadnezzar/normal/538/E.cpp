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

int n;
vector <int> graph[MAXN];

pair <pii, int> dfs(int v, int l) {
    if (!szof(graph[v])) {
        //cout << v << " 0 0 1" << endl;
        return mapa(mapa(0, 0), 1);
    }
    vector <pair <pii, int> > vec;
    int numc = 0;
    for (int i = 0; i < szof(graph[v]); ++i) {
        pair <pii, int> p = dfs(graph[v][i], l + 1);
        vec.puba(p);
        numc += p.ss;
    }
    int tmp = l & 1;
    pii ret = mapa(MAXN, -1);
    if (tmp == 0) {
        for (int i = 0; i < szof(vec); ++i) {
            ret.ss = max(ret.ss, numc - vec[i].ss + vec[i].ff.ss);
        }
        ret.ff = 0;
        for (int i = 0; i < szof(vec); ++i) {
            ret.ff += vec[i].ff.ff + 1;   
        }
        ret.ff -= 1;
    } else {
        for (int i = 0; i < szof(vec); ++i) {
            ret.ff = min(ret.ff, vec[i].ff.ff);
        }
        ret.ss = numc;
        for (int i = 0; i < szof(vec); ++i) {
            ret.ss -= vec[i].ss - vec[i].ff.ss;
        }
        //ret.ss += 1;
    }

    //cout << v << " " << ret.ff << " " << ret.ss << " " << numc << endl;

    return mapa(ret, numc);
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;--v;
        graph[u].puba(v);
    }

    pair <pii, int> p = dfs(0, 0);

    cout << p.ff.ss + 1 << " " << p.ff.ff + 1 << endl;

    return 0;
}