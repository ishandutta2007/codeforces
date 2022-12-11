#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
vector<int> T[N];
bool vis[N];

int cl[N];
int id[N];
int cnt;
int best[N];

void dfs(int u, int pr){
    if(cl[u] != -1) return;
    cl[u] = pr;
    id[u] = cnt;
    for(auto p : T[u]){
        if(cl[p] != -1 && cl[p] == pr){
            cout << "-1";
            exit(0);
        }
        dfs(p, !pr);
    }
}

int dist[N];


int main(){
    int n, m;
    cin >> n >> m;
    int a, b;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> a >> b;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    for(int i = 1; i <= n; i ++ )
        cl[i] = -1;
    for(int i = 1; i <= n; i ++ ){
        if(cl[i] == -1){
            cnt++;
            dfs(i,0);
        }
    }
    int cur;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ )
            dist[j] = -1;
        dist[i] = 0;
        queue<int> ff;
        ff.push(i);
        while(!ff.empty()){
            cur = ff.front();
            best[id[i]] = max(best[id[i]], dist[cur]);
            ff.pop();
            for(auto p : T[cur]){
                if(dist[p] == -1){
                    ff.push(p);
                    dist[p] = dist[cur] + 1;
                }
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= cnt; i ++ ){
        res += best[i];
    }
    cout << res;
    return 0;
}