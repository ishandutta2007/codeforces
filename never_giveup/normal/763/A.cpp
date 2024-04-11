/*
ID: ramil-p1
PROG: balancing
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double ld;

const int maxn = 2e5 + 100, inf = 1e9 + 100;

int c[maxn];

vector<int> e[maxn];

int up[maxn], good[maxn];

int n;

void dfs(int v, int par){
    good[v] = 1;
    for (int i = 0; i < e[v].size(); i++)
    if (e[v][i] != par){
        dfs(e[v][i], v);
        if (c[e[v][i]] != c[v] || !good[e[v][i]])
            good[v] = 0;
    }
}

void dfs0(int v, int par){
    vector<int> pref(e[v].size() + 1), suf(e[v].size() + 1);
    pref[0] = 1;
    for (int i = 0; i < e[v].size(); i++)
        if (e[v][i] != par)
            pref[i + 1] = (pref[i] && (good[e[v][i]] && c[e[v][i]] == c[v]));
        else
            pref[i + 1] = (pref[i] && (up[v] && c[par] == c[v]));
    suf[e[v].size()] = 1;
    for (int i = (int)e[v].size() - 1; i >= 0; i--)
        if (e[v][i] != par)
            suf[i] = (suf[i + 1] && (good[e[v][i]] && c[e[v][i]] == c[v]));
        else
            suf[i] = (suf[i + 1] && (up[v] && c[par] == c[v]));
    for (int i = 0; i < e[v].size(); i++)
        if (e[v][i] != par)
            up[e[v][i]] = (pref[i] && suf[i + 1]);
    bool is = up[v];
    for (int i = 0; i < e[v].size(); i++)
        if (e[v][i] != par && !good[e[v][i]])
            is = 0;
    if (is){
        cout << "YES\n" << v + 1;
        exit(0);
    }
    for (int i = 0; i < e[v].size(); i++)
        if (e[v][i] != par)
            dfs0(e[v][i], v);
}

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++){
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
        cin >> c[i];
    up[0] = 1;
    dfs(0, -1);
    dfs0(0, -1);
    cout << "NO";
}