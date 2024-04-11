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
const int INF = 1e9 + 9;

int n;
LL w[MAXN];
vector <int> graph[MAXN];

pair <LL, LL> dfs(int v) {
    vector <pair <LL, LL> > vec;
    for (int i = 0; i < szof(graph[v]); ++i) {
        vec.puba(dfs(graph[v][i]));
    }
    pair <LL, LL> now = mapa(0, -INF);
    for (int i = 0; i < szof(vec); ++i) {        
        now = mapa(max(now.ff + vec[i].ff, now.ss + vec[i].ss), max(now.ff + vec[i].ss, now.ss + vec[i].ff));
    }
    now.ss = max(now.ss, now.ff + w[v]);
    //cout << v << " " << now.ff << " " << now.ss << endl;
    return now;
}

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p >> w[i];
        if (i != 0) {
            graph[p - 1].puba(i);
        }
    }

    pair <LL, LL> tmp = dfs(0);

    cout << max(tmp.ff, tmp.ss) << endl;

    return 0;
}