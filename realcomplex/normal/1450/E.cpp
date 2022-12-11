#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 205;
const int INF = (int)1e9;
int dis[N][N];

vector<int> T[N];
int bit[N];

void dfs(int u){
    for(auto x : T[u]){
        if(bit[x]==-1){
            bit[x]=(bit[u]^1);
            dfs(x);
        }
        else if(bit[x] == bit[u]){
            cout << "NO\n";
            exit(0);
        }
    }
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int u, v, t;
    for(int i = 1; i <= n; i ++ ){
        bit[i]=-1;
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            if(i == j) dis[i][j]=0;
            else dis[i][j]=INF;
        }
    }
    for(int i = 0 ; i < m ; i ++ ){
        cin >> u >> v >> t;
        if(t){
            dis[u][v]=+1;
            dis[v][u]=-1;
        }
        else{
            dis[u][v]=1;
            dis[v][u]=1;
        }
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(1);
    for(int k = 1; k <= n; k ++ ){
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= n; j ++ ){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        if(dis[i][i] < 0){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    int mx=0;
    v = 1;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            if(dis[i][j] > mx){
                mx = dis[i][j];
                v = i;
            }
        }
    }
    cout << mx << "\n";
    for(int i = 1; i <= n; i ++ ){
        cout << dis[v][i] << " ";
    }
    cout << "\n";
    return 0;
}