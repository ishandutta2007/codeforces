#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pair<int,int> pii
#define abs(a) ((a<0) ? -a : a)
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);

const int N = (int)3e5 + 9;
const int AL = 26;
int cnt[N];
char let[N];
int dp[N][AL];
int vis[N];
vector<int>edge[N];

bool dfs(int cur){
    if(vis[cur]==1)return true;
    if(vis[cur]==2)return false;
    vis[cur]=1;
    for(auto x : edge[cur]){
        if(dfs(x))return true;
    }
    vis[cur]=2;
    return false;
}


int main(){
    fastIO;
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> let[i];
        dp[i][let[i]-'a']=1;
    }
    int a,b;
    while(m--){
        cin >> a >> b;
        cnt[b]++;
        edge[a].push_back(b);
    }
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i)){
                cout << "-1\n";
                return 0;
            }
        }
    }
    queue<int>grp;
    for(int i = 1;i<=n;i++)if(cnt[i]==0)grp.push(i);
    int cur_node;
    int ans = 1;
    while(!grp.empty()){
        cur_node=grp.front();grp.pop();
        for(auto x : edge[cur_node]){
            for(int i = 0;i<26;i++)
                dp[x][i]=max(dp[x][i],dp[cur_node][i]+((char)i+97==let[x])),ans=max(ans,dp[x][i]);
            cnt[x]--;
            if(cnt[x]==0)
                grp.push(x);
        }
    }
    cout << ans << "\n";
    return 0;
}