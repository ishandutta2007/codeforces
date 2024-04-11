#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = 105;

int dp[N][N][26];//victor if lucas starts at pos i and max starts at pos j
bool visited[N][N][26];
vector<pii> adj[N];

void dfs(int p1, int p2, int lis){
    if(visited[p1][p2][lis])//already visited state
        return;
    int ans = 2;
    for(auto x : adj[p1]){
        if(x.se<lis)//not valid
            continue;
        dfs(p2,x.fi,x.se);
        if(dp[p2][x.fi][x.se]==2)
            ans = 1;
    }
    dp[p1][p2][lis] = ans;
    visited[p1][p2][lis] = true;
}

int main(){
    fastIO;
    int n,m;
    cin >> n >> m;
    int a,b;
    char k;
    while(m--){
        cin >> a >> b >> k;
        k-='a';
        adj[a].push_back(mp(b,(int)k));
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dfs(i,j,0);
            cout << ((dp[i][j][0] == 1) ? "A" : "B");
        }
        cout << "\n";
    }
    return 0;
}