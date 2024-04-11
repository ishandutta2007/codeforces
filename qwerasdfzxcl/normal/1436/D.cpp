#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> adj[200005];
ll citizen[200005];
ll g[200005]={0};
ll sum[200005]={0};
ll pc[200005]={0};

void dfs(int s){
    sum[s] += citizen[s];
    pc[s] = 1;
    for (int i=0;i<adj[s].size();i++){
        dfs(adj[s][i]);
        pc[s] += pc[adj[s][i]];
        sum[s] += sum[adj[s][i]];
        g[s]=max(g[s], g[adj[s][i]]);
    }
    if (adj[s].size()!= 0) pc[s] -= 1;
    ll tmp;
    if (sum[s]%pc[s]==0) tmp=sum[s]/pc[s];
    else tmp=sum[s]/pc[s]+1;
    g[s]=max(g[s], tmp);
}

int main()
{
    ll n;
    scanf("%lld", &n);
    for (ll i=0;i<n-1;i++){
        int tmp;
        scanf("%d", &tmp);
        adj[tmp].push_back(i+2);
    }
    for (ll i=0;i<n;i++){
        scanf("%lld", &citizen[i+1]);
    }
    dfs(1);
    printf("%lld", g[1]);
    return 0;
}