#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define pb push_back
#define all(a) a.begin(),a.end()
using namespace std;
const int maxn = 2e5+5;
int n;
vector<int> g[maxn];
vector<int> ned[maxn];
int d[maxn];
int dp[maxn];
void mian(){
    cin>>n;
    fors(i,0,n+1) g[i].clear(), ned[i]. clear(), d[i] = 0, dp[i] = 0;
    fors(i,1,n+1){
        int k; scanf("%d", &k);
        while(k--){
            int x; scanf("%d", &x); ned[i].pb(x), g[x].pb(i), d[i]++;
        }
    }
    vector<int> a;
    queue<int> q;  fors(i,1,n+1) if(d[i] == 0) q.push(i);
    while(q.size()){
        int u = q.front(); q.pop(); a.pb(u);
        for(int v:g[u]){
            if(--d[v] == 0) q.push(v);
        }
    }
    if(a.size() != n){
        puts("-1"); return;
    }
    fors(i,0,a.size()){
        int u = a[i]; dp[u] = 1;
        for(int x: ned[u]) if(u < x) dp[u] = max(dp[u], dp[x]+1); else dp[u] = max(dp[u], dp[x]);
    }
    int ans = 0;
    for(int x:a) ans = max(ans, dp[x]);
    cout<<ans<<endl;
    return;
}
int main(){
    int T; cin>>T;
    while(T--) mian();
}