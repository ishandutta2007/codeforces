#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef pair<int, int> pie;

const int maxn = 1e5 + 10;
vector<pie> adj[maxn];
int d[maxn];

void Dijkstra(int v){
    set<pie> s;
    memset(d, 127, sizeof d);
    s.insert(MP(0, v));
    d[v] = 0;
    while(s.size()){
        int x = s.begin()->R;
        s.erase(*s.begin());
        for(int i = 0; i < adj[x].size(); i++){
            int y = adj[x][i].L;
            if(d[y] > d[x] + adj[x][i].R){
                s.erase(MP(d[y], y));
                d[y] = d[x] + adj[x][i].R;
                s.insert(MP(d[y], y));
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m, sour, l;
    cin >> n >> m >> sour;
    while(m--){
        int fi, se, th;
        cin >> fi >> se >> th;
        adj[fi].PB(MP(se, th));
        adj[se].PB(MP(fi, th));
    }
    cin >> l;
    Dijkstra(sour);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(d[i] == l)
            ans += 2;
        int x = i;
        for(int j = 0; j < adj[i].size(); j++){
            int y = adj[i][j].L,
                w = adj[i][j].R;
            if(d[x] < l){
                if(d[y] < l){
                    if(l - d[x] + l - d[y] < w)
                        ans += 2;
                    else if(l - d[x] + l - d[y] == w)
                        ans++;
                }
                else if(d[y] >= l and l - d[x] < w and l - d[x] > 0)
                    ans++;
            }
            else if(d[x] >= l)
                if(d[y] < l)
                    if(l - d[y] < w and l - d[y] > 0)
                        ans++;
        }
    }
    cout << ans/2 << endl;
    return 0;
}