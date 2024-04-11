#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100;

int n;

int f[maxn], parent[maxn];

int dsu_get(int x){
    return x == parent[x] ? x : parent[x] = dsu_get(parent[x]);
}

void dsu_unite(int x, int y){
    x = dsu_get(x), y = dsu_get(y);
    if (x > y)
        swap(x, y);
    if (x != y)
        parent[y] = x;
}

vector<int> e[maxn];

int m;

int g[maxn], h[maxn];

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    #endif // ONPC
    cin >> n;
    for (int i = 0; i < n; i++)
        parent[i] = i, cin >> f[i], f[i]--;
    for (int i = 0; i < n; i++){
        dsu_unite(i, f[i]);
        if (f[dsu_get(i)] != f[i]){
            cout << -1;
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
        e[dsu_get(i)].push_back(i);
    for (int i = 0; i < n; i++)
    if (!e[i].empty()){
        h[m] = f[e[i][0]];
        for (int j = 0; j < e[i].size(); j++)
            g[e[i][j]] = m;
        m++;
    }
    cout << m << '\n';
    for (int i = 0; i < n; i++)
        cout << g[i] + 1 << ' ';
    cout << '\n';
    for (int i = 0; i < m; i++)
        cout << h[i] + 1 << ' ';
}