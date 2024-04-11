#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e3 + 100, inf = 1e9 + 100, mod = 1e9 + 993;

int n, m, w;

int q[maxn][2], b[maxn], c[maxn];

bool vis[maxn];

vector<int> e[maxn];

void upd(pair<int, int> x){
    for (int i = w - x.first; i >= 0; i--)
        q[i + x.first][1] = max(q[i + x.first][1], q[i][0] + x.second);
}

pair<int, int> dfs(int v){
    pair<int, int> ret = make_pair(c[v], b[v]);
    vis[v] = 1;
    upd(make_pair(c[v], b[v]));
    for (int i = 0; i < e[v].size(); i++)
        if (!vis[e[v][i]]){
            pair<int, int> x = dfs(e[v][i]);
            ret.first += x.first;
            ret.second += x.second;
        }
    return ret;
}

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> n >> m >> w;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
        if (!vis[i]){
            upd(dfs(i));
            for (int j = 0; j < maxn; j++)
                q[j][0] = max(q[j][0], q[j][1]), q[j][1] = 0;
        }
    int answer = 0;
    for (int i = 0; i < maxn; i++)
        answer = max(answer, q[i][0]);
    cout << answer;
}