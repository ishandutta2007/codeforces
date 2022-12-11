#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
vector<int> T[N];
int dp[N];
int dep[N];
int mx[N];

void dfs(int u, int p){
    mx[u]=dep[u];
    for(auto x : T[u]){
        if(x==p) continue;
        dep[x]=dep[u]+1;
        dfs(x,u);
        mx[u]=max(mx[u],mx[x]);
        dp[u]+=dp[x];
    }
    mx[u]=max(mx[u],dep[u]);
    dp[u]=max(dp[u],mx[u]-dep[u]+1);
}

int main(){
    fastIO;
    int n;
    cin >> n;
    int p;
    for(int i = 2; i <= n; i ++ ){
        cin >> p;
        T[p].push_back(i);
    }
    dfs(1, -1);
    cout << dp[1] << "\n";
    return 0;
}