#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 100010
#define N2 2000010

using namespace std;

int n, q;
int e[N2], ans[N], d, id[N2], h[N];
vector <int> uoc[N], ke[N];
vector <int> snt[200000];

void Cbi() {
    e[1] = 1;
    for(int i = 2; i < N2; i++)
    if(!e[i]) {
        id[i] = ++d;
        for(int j = i; j < N2; j += i) e[j] = i;
    }
}

void DFS(int u, int par) {
    h[u] = h[par] + 1;
    int res = 0;
    for(int i = 0; i < (int)uoc[u].size(); i++){
            int prime = id[uoc[u][i]];
            if(snt[prime].size()) {
                int hh = snt[prime][(int)snt[prime].size() - 1];
                if(h[hh] > h[res]) res = hh;
            }
            snt[prime].push_back(u);
    }
    ans[u] = res? res : -1;
    for(int i = 0; i < (int)ke[u].size(); i++) {
        int v = ke[u][i];
        if(v != par) DFS(v, u);
    }
    for(int i = 0; i < (int)uoc[u].size(); i++) {
        int prime = id[uoc[u][i]];
        snt[prime].pop_back();
    }
}

void Pt( vector <int> &v, int x)
{
    v. clear();
    while(x > 1) {
        int y = e[x];
        x /= y;
        if((int)v.size() && v[(int)v.size() - 1] == y) continue;
        v.push_back(y);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    Cbi();
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        Pt(uoc[i], x);
    }
    for(int i = 1; i < n; i++) {
        int u , v;
        cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    h[0] = 0;
    DFS(1, 0);
    while(q--) {
        int type, v;
        cin >> type >> v;
        if(type == 1) cout << ans[v] << endl;
        else {
            int x;
            cin >> x;
            Pt(uoc[v], x);
            DFS(1, 0);
        }
    }
    return 0;
}