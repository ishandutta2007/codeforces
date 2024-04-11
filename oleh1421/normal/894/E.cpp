//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
const int N=1000010;
vector<pair<int,int> >g[N];
vector<pair<int,int> >rg[N];
bool used[N];
vector<int>order;
void dfs(int v){
    used[v]=true;
    for (auto cur:g[v]){
        int to=cur.first;
        if (!used[to]){
            dfs(to);
        }
    }
    order.push_back(v);
}
int col[N];
void dfs1(int v){
    for (auto cur:rg[v]){
        int to=cur.first;
        if (!col[to]){
            col[to]=col[v];
            dfs1(to);
        }
    }
}
vector<pair<int,int> >gg[N];
ll val[N];
ll f(ll x){
    ll y=0ll;
    for (int i=15;i>=0;i--){
        y+=(1<<i);
        if (y*(y+1ll)/2ll>x) y-=(1<<i);
    }
//    res=
//    res+=;

    ll res=x*(y+1)-(y*(y+1ll)*(y+1ll)/2ll-y*(y+1ll)*(y+y+1ll)/6ll);
//    cout<<x<<" "<<res<<" "<<y<<endl;
    return res;
//    i*(y-i+1)
//    i*(y+1)-i*i

}
ll dp[N];
bool used2[N];
void dfs2(int v){
    used2[v]=true;
    dp[v]=val[v];
    for (auto cur:gg[v]){
        int to=cur.first;
        ll w=cur.second;
        if (!used2[to]) dfs2(to);
        dp[v]=max(dp[v],val[v]+dp[to]+w);
    }
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back({b,c});
        rg[b].push_back({a,c});
    }
    int s;cin>>s;
    for (int i=1;i<=n;i++){
        if (!used[i]) dfs(i);
    }
    reverse(order.begin(),order.end());
    int comp=0;
    for (int v:order){
        if (!col[v]){
            col[v]=++comp;
            dfs1(v);
        }
    }
    for (int v=1;v<=n;v++){
        for (auto cur:g[v]){
            int to=cur.first;
            if (col[v]==col[to]){
//                cout<<"OOOK "<<
//                if (v<to){
                    val[col[v]]+=f(cur.second);
//                }
            } else {

                gg[col[v]].push_back({col[to],cur.second});
            }
        }
    }
    dfs2(col[s]);
    cout<<dp[col[s]]<<endl;



}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
/**
2 2
1 2 10
2 1 10
1

**/