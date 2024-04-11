//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=1500010;
const ll inf=2e18;
const ll mod=1000000007;
vector<int>g[N];
vector<pair<int,int> >T;
vector<pair<int,int> >good;
vector<pair<int,int> >bad;
int col[N];
int p[N];
bool used[N];
int tin[N];
int timer=0;
void dfs(int v,int pr){
    col[v]=(col[pr]^1);
    used[v]=true;
    tin[v]=++timer;
//    cout<<v<<endl;
    for (int to:g[v]){
        if (!used[to]){
            dfs(to,v);
            T.push_back({v,to});
        } else if (tin[to]<tin[v]){
//            cout<<to<<" "<<v<<" "<<col[to]<<" "<<col[v]<<endl;
            if (col[v]==col[to]){
                bad.push_back({to,v});
            } else if (to!=pr) {
                good.push_back({to,v});
            }
        }
    }
}
int add[N];
void dfs1(int v,int pr){
    p[v]=pr;
    for (int to:g[v]){
        if (to==pr) continue;
        dfs1(to,v);
        add[v]+=add[to];
    }
//    cout<<v<<" "<<add[v]<<endl;

}
void solve(int Case){

    int n,m;cin>>n>>m;
    T.clear();
    good.clear();
    bad.clear();
    timer=0;
    for (int i=1;i<=n;i++){
        g[i].clear();
        used[i]=false;
        col[i]=0;
        add[i]=0;
        tin[i]=0;
    }
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    if (bad.size()<=1){
        if (bad.size()==1 && col[bad[0].first]==0){
            for (int i=1;i<=n;i++) col[i]^=1;
        }
        cout<<"YES\n";
        for (int i=1;i<=n;i++) cout<<col[i];
        cout<<endl;
        return;
    }
//    for (int i=1;i<=n;i++) cout<<col[i];
//    cout<<endl;
    for (int i=1;i<=n;i++) g[i].clear();
    for (auto cur:T){
        g[cur.first].push_back(cur.second);
        g[cur.second].push_back(cur.first);
//        cout<<cur.first<<" "<<cur.second<<endl;
    }
    for (auto cur:bad){
//        cout<<cur.first<<" "<<cur.second<<endl;
        add[cur.first]-=1;
        add[cur.second]+=1;
    }
    for (auto cur:good){
        add[cur.first]+=1;
        add[cur.second]-=1;
    }
    dfs1(1,0);
    for (int i=1;i<=n;i++) g[i].clear();
    int a=-1,b=-1;
    for (int i=2;i<=n;i++){
        if (add[i]==(int)bad.size()){
            a=i;
            b=p[i];
            break;
        }
    }
    if (a==-1){
        cout<<"NO\n";
        return;
    }
    for (auto cur:T){
        if (cur.first==a && cur.second==b) continue;
        if (cur.first==b && cur.second==a) continue;
        g[cur.first].push_back(cur.second);
        g[cur.second].push_back(cur.first);
    }
    for (auto cur:bad){
        if (cur.first==a && cur.second==b) continue;
        if (cur.first==b && cur.second==a) continue;
        g[cur.first].push_back(cur.second);
        g[cur.second].push_back(cur.first);
    }
    for (auto cur:good){
        if (cur.first==a && cur.second==b) continue;
        if (cur.first==b && cur.second==a) continue;
        g[cur.first].push_back(cur.second);
        g[cur.second].push_back(cur.first);
    }
    bad.clear();
    good.clear();
    T.clear();
    timer=0;
    for (int i=0;i<=n;i++){
        used[i]=false;
        tin[i]=0;

    }
    dfs(1,0);
    if (col[a]==col[b]) bad.push_back({a,b});
    if (bad.size()<=1){

        if (bad.size()==1 && col[bad[0].first]==0){
            for (int i=1;i<=n;i++) col[i]^=1;
        }
        cout<<"YES\n";
        for (int i=1;i<=n;i++) cout<<col[i];
        cout<<endl;
        return;
    }
    cout<<"NO\n";

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**
1
4 5
1 2
2 3
3 4
1 3
2 4
**/