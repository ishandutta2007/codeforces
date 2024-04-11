#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 100, inf = 1e9 + 100;

int n, k, d;

int p[maxn];

vector<pair<int, int> > e[maxn];

int que[maxn], cnt, it;

int vis[maxn];

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    scanf("%d %d %d", &n, &k, &d);
    int nk = 0;
    for (int i = 0; i < k; i++){
        int x;
        scanf("%d", &x);
        if (!vis[x - 1])
            que[cnt] = x - 1, cnt++, vis[x - 1] = x, nk++;
    }
    k = nk;
    for (int i = 0; i < n - 1; i++){
        int v, u;
        scanf("%d %d", &v, &u);
        v--;
        u--;
        e[v].push_back(make_pair(u, i));
        e[u].push_back(make_pair(v, i));
    }
    printf("%d\n", k - 1);
    while (it < cnt){
        int v = que[it];
        it++;
        for (int i = 0; i < e[v].size(); i++){
            int to = e[v][i].first;
            if (vis[to] == 0)
                vis[to] = vis[v], que[cnt] = to, cnt++;
            else
            if (vis[to] != vis[v]){
                if (v < to)
                    printf("%d ", e[v][i].second + 1);
            }
        }
    }
}