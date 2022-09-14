//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
vector<int>g[N];
vector<int>cyc;
int h[N];
bool used[N];
bool in_cyc[N];
vector<int>order;
bool Found=false;
void dfs(int v,int pr){
    order.push_back(v);
    used[v]=true;
    h[v]=h[pr]+1;
    for (int to:g[v]){
        if (to==pr) continue;
        if (used[to]){
            if (!Found){
                for (int i=h[to];i<order.size();i++){
                    cyc.push_back(order[i]);
                }
                Found=true;
            }
        } else {
            dfs(to,v);
        }
    }
    order.pop_back();
}
ll Sz=0;
void dfs1(int v,int pr){
    Sz++;
    for (int to:g[v]){
        if (to!=pr && !in_cyc[to]){
            dfs1(to,v);
        }
    }
}
void solve(){
    ll n;cin>>n;
    for (int i=1;i<=n;i++) g[i].clear();
    for (int i=1;i<=n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    h[0]=-1;
    Found=false;
    for (int i=1;i<=n;i++) used[i]=in_cyc[i]=false;
    order.clear();
    cyc.clear();
    dfs(1,0);
    for (int i:cyc){
        in_cyc[i]=true;
    }
    ll res=n*n;
    for (int i:cyc){
        Sz=0;
        dfs1(i,0);
        res+=(Sz-1ll)*Sz/2ll;
        res-=Sz*Sz;
    }

    cout<<res<<endl;


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}