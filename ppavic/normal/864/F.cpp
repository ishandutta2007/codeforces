#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 3e3 + 10;
const int LOG = 13;
const int INF = 0x3f3f3f3f;

typedef short int sint;
typedef pair < sint,sint> pii;

sint oddo[N][N];
sint dp[N][N][LOG];
sint bio[N];
sint n,m;
int q;

vector < pii > edge;
vector < sint > g[N];

void dfs(int i,int j){
    oddo[j][i] = 1;bio[i] = 1;
    for(int k = 0;k<g[i].size();k++){
        if(bio[g[i][k]]) continue;
        dfs(g[i][k], j);
    }
}

void nxt(){
    memset(dp,INF,sizeof(dp));
    for(int i = 0;i<edge.size();i++){
        sint x = edge[i].first,y = edge[i].second;
        for(int j = 1;j<=n;j++){
            if(oddo[y][j])
                dp[x][j][0] = min(dp[x][j][0], y);
        }
    }
}

void calc(){
    for(int i = 1;i<=n;i++)
        dp[i][i][0] = i;
    for(int lg = 1;lg < LOG;lg++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(dp[i][j][lg - 1] > n) continue;
                dp[i][j][lg] = dp[dp[i][j][lg - 1]][j][lg - 1];
            }
        }
    }
}

sint get(int i,int j,int k){
    if(!oddo[i][j]) return -1;
    if(dp[i][j][LOG-1] != j) return -1;
    k--;
    sint k2 = k -1;
    int cur = i,cur2 = i;
    for(int i = 0;i<LOG;i++){
        if(cur <= n && k & (1 << i)) cur = dp[cur][j][i];
        if(cur <= n && k2 & (1 << i)) cur2 = dp[cur2][j][i];
    }
    if(cur == cur2) return -1;
    return cur;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 0;i<m;i++){
        sint x,y;cin >> x >> y;
        g[x].push_back(y);
        edge.push_back(make_pair(x,y));
    }

    for(int i = 1;i<=n;i++){
        memset(bio,0,sizeof(bio));
        dfs(i,i);
    }
    nxt();
    calc();
    for(int i = 0;i<q;i++){
        sint a,b,c;
        cin >> a >> b >> c;
        cout << get(a,b,c) << "\n";
    }
}