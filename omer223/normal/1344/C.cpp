#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz=3e5;
int n,m;
vector<int> adj[sz],radj[sz];
int indeg[sz];
int ass[sz];//all=1,exist=2,no=0
bitset<sz> vis, rvis;

void dfs(int src){
    vis[src]=1;
    for (int y : adj[src]){
        if(!vis[y])dfs(y);
    }
}

void rdfs(int src){
    rvis[src]=1;
    for (int y : radj[src]){
        if(!rvis[y])rdfs(y);
    }
}

bool dag() {
    queue<int> q;
    int cnt=0;
    foru(i,0,n){
        if(!indeg[i])q.push(i);
    }
    while(!q.empty()) {
        int x = q.front();q.pop();cnt++;
        for (int y : adj[x]){
            indeg[y]--;
            if(!indeg[y])q.push(y);
        }
    }
    return (cnt==n);
}

int main() {
    fast;
    cin>>n>>m;
    foru(i,0,m){
        int x,y;
        cin>>x>>y;
        adj[--x].pb(--y);
        radj[y].pb(x);
        indeg[y]++;
    }
    if(!dag()){
        cout<<-1<<'\n';
        return 0;
    }
    int alls=0;
    foru(i,0,n){
        if(!vis[i]&&!rvis[i])ass[i]=1,alls++;
        else ass[i]=2;
        dfs(i);
        rdfs(i);
    }
    cout<<alls<<'\n';
    foru(i,0,n){
        if(ass[i]==1)cout<<'A';
        else cout<<'E';
    }
    return 0;
}