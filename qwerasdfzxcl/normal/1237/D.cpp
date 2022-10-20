#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> adj[100100];
int a[100100], dp[100100], deg[100100];
bool visited[100100];
int n;

void dfs(int s){
    if (visited[s]) return;
    visited[s]=1;
    for (int v:adj[s]){
        if (!visited[v]) dp[v]=dp[s]+(s+n-v)%n;
        dfs(v);
    }
}

int main(){
    scanf("%d", &n);
    int mx=-1, mn=2000000000;
    for (int i=0;i<n;i++){
        scanf("%d", a+i);
        mx=max(a[i], mx);
        mn=min(a[i], mn);
    }
    if (mx<=2*mn){
        for (int i=0;i<n;i++) printf("-1 ");
        return 0;
    }
    for (int i=0;i<n;i++) dp[i]=1e9;
    int midx;
    for (int i=0;i<n;i++) if (a[i]==mx){
        midx=i; break;
    }
    for (int i=0;i<n;i++){
        int cidx=(midx+i)%n;
        if (a[cidx]*2<mx){
            dp[midx]=i;
            break;
        }
    }
    deque<int> dq;
    for(int i=1;i<n;i++){
        int cidx=(midx+i)%n;
        while(!dq.empty() && a[dq.front()]>a[cidx]*2){
            dp[dq.front()]=(cidx+n-dq.front())%n;
            dq.pop_front();
        }
        while(!dq.empty() && a[dq.back()]<=a[cidx]){
            adj[cidx].push_back(dq.back());
            deg[dq.back()]++;
            dq.pop_back();
        }
        dq.push_back(cidx);
    }
    while(!dq.empty()){
        adj[midx].push_back(dq.back());
        deg[dq.back()]++;
        dq.pop_back();
    }
    for (int i=0;i<n;i++) if (deg[i]==0) dfs(i);
    //for (int i=0;i<n;i++) printf("%d ", dp[i]);
    for (int i=0;i<n;i++) assert(dp[i]<1e9);
    for (int i=0;i<n;i++) printf("%d ", dp[i]);
    return 0;
}