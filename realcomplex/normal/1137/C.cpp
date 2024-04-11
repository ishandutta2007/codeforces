#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
const int M = 50*N;
int d, n;

vector<int> T[N];
vector<int> R[N];
vector<int> G[M];
bool vis[M];
bool vis1[M];
int id[M];
int can[N][50];

int getid(int p, int q){
    return (p - 1) * d + q;
}

vector<int> ord;

void dfs(int x){
    int p = x/d+1, q = x%d;
    vis[x]=true;
    int id;
    for(auto j : T[p]){
        id=getid(j,(q+1)%d);
        if(!vis[id]){
            dfs(id);
        }
    }
    ord.push_back(x);
}

int cur;
void dfs1(int x){
    int p = x/d+1, q = x%d;
    vis1[x]=true;
    id[x]=cur;
    int id;
    for(auto j : R[p]){
        id=getid(j,(q+d-1)%d);
        if(!vis1[id] && vis[x]){
            dfs1(id);
        }
    }
}

bool has[M];
int dp[M];

int main(){
    fastIO;
    int m;
    cin >> n >> m >> d;
    int u, v;
    for(int i = 1; i <= m; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        R[v].push_back(u);
    }
    char f;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 0 ; j < d; j ++ ){
            cin >> f;
            can[i][j]=f-'0';
        }
    }
    dfs(0);
    reverse(ord.begin(), ord.end());
    for(auto x : ord){
        if(!vis1[x]){
            cur++;
            dfs1(x);
        }
    }
    reverse(ord.begin(), ord.end());
    int ii;
    for(int i = 1; i <= n; i ++ ){
        vector<int> lis;
        for(int j = 0 ;j < d; j ++ ){
            ii=getid(i,j);
            if(vis[ii] && !has[id[ii]] && can[i][j]){
                has[id[ii]]=true;
                dp[id[ii]]++;
                lis.push_back(id[ii]);
            }
        }
        for(auto r : lis){
            has[r]=false;
        }
    }
    int ni;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 0 ; j < d; j ++ ){
            ni=getid(i,j);
            if(vis[ni]){

                for(auto x : T[i]){
                    ii = getid(x, (j+1)%d);
                    if(id[ni]!=id[ii]){
                        G[id[ni]].push_back(id[ii]);
                    }
                }
            }
        }
    }
    int li;
    int ans=0;
    for(int k = cur; k >= 1; k -- ){
        li = 0;
        for(auto p : G[k]){
            li=max(li,dp[p]);
        }
        dp[k]+=li;
        ans=max(ans,dp[k]);
    }
    cout << ans << "\n";
    return 0;
}