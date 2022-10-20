#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 100010;

struct query {
    int type, x, y;
}q[N];

int n, m, cnt;
bool check[N];
int in[N], out[N], par[N];
vector <int> a[N];
pair <int, int> Packet[N];

void DFS(int u) {
    in[u] = ++cnt;
    for(int i = 0; i < (int)a[u].size(); i++)
        DFS(a[u][i]);
    out[u] = ++cnt;
}

int Getroot(int u) {
    return par[u]? (par[u] = Getroot(par[u])) : u;
}

bool Con(int u, int v) {
    return (in[v] <= in[u] && out[v] >= out[u]);
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> q[i].type >> q[i].x;
        if(q[i].type != 2) {
            cin >> q[i].y;
            if(q[i].type == 1) a[q[i].y].push_back(q[i].x), check[q[i].x] = 1;
        }
    }
    for(int i = 1; i <= n; i++)
        if(!check[i]) DFS(i);
    cnt = 0;
    for(int i = 1; i <= m; i++) {
        if(q[i].type == 1) par[q[i].x] = q[i].y;
        if(q[i].type == 2) Packet[++cnt] = make_pair(q[i].x, Getroot(q[i].x));
        if(q[i].type == 3) {
            int x = q[i].x, be = Packet[q[i].y].first, lon = Packet[q[i].y].second;
            if(Con(x, lon) && Con(be, x))  cout << "YES";
            else cout << "NO";
            cout << endl;
        }
    }
    return 0;
}