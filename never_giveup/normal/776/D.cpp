#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100;

vector<int> e[maxn];

int n, m;

vector<int> s[maxn];

bool st[maxn];

int f(int x){
    return x + m;
}

int parent[maxn];

int dsu_get(int x){
    return x == parent[x] ? x : parent[x] = dsu_get(parent[x]);
}

void dsu_unite(int x, int y){
    x = dsu_get(x), y = dsu_get(y);
    if (x == y)
        return;
    parent[x] = y;
}

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int v;
        cin >> v;
        st[i] = v ^ 1;
    }
    for (int i = 0; i < m; i++){
        int cnt;
        cin >> cnt;
        parent[i] = i;
        parent[f(i)] = f(i);
        for (int j = 0; j < cnt; j++){
            int x;
            cin >> x;
            s[x - 1].push_back(i);
        }
    }
    for (int i = 0; i < n; i++){
        if (st[i]){
            dsu_unite(f(s[i][0]), s[i][1]);
            dsu_unite(f(s[i][1]), s[i][0]);
        }
        else{
            dsu_unite(s[i][0], s[i][1]);
            dsu_unite(f(s[i][0]), f(s[i][1]));
        }
    }
    for (int i = 0; i < m; i++)
    if (dsu_get(i) == dsu_get(f(i))){
        cout << "NO";
        return 0;
    }
    cout << "YES";
}