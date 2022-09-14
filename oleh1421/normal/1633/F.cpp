#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-12;
const int N=200010;
const ll mod=998244353;
#define ADD(a,b) a+=b;if (a>=mod) a-=mod
//#define endl '\n'
vector<pair<int,int> >g[N];
int p[N];
int xr[N];
int ind[N];
int sz[N];
int mx[N];
int tin[N];
int up[N];
int timer=0;
void dfs(int v,int pr){
    p[v]=pr;
    sz[v]=1;
    mx[v]=0;
    for (auto cur:g[v]){
        int to=cur.first;
        if (to==pr) continue;
        dfs(to,v);
        sz[v]+=sz[to];
        if (sz[to]>sz[mx[v]]) mx[v]=to;
    }
}
void dfs1(int v,int gl){
    tin[v]=++timer;
    up[v]=gl;
    if (!mx[v]) return;
    dfs1(mx[v],gl);
    for (auto cur:g[v]){
        int to=cur.first;
        if (to==p[v]) continue;
        if (to==mx[v]){
            ind[tin[mx[v]]]=cur.second;
            continue;
        }
        dfs1(to,to);
//        cout<<to<<" "<<tin[to]<<" "<<cur.second<<endl;
        ind[tin[to]]=cur.second;
    }
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }
    dfs(1,0);
    dfs1(1,1);
    ll sum=0;
    int cnt=1;
    xr[1]=1;
    int tot=1;
//    int A=0;
    while (true){
        int type;cin>>type;
        if (type==3) break;
        if (type==1){
            tot++;
            int v;cin>>v;
            while (v){
//                C++;
//                if (C>=30) exit(1);
                int l=tin[up[v]];
                int r=tin[v];
                for (int i=l;i<=r;i++){
                    sum+=(1-2*xr[i])*ind[i];
                    cnt+=(1-2*xr[i]);
                    xr[i]^=1;
                }
                v=p[up[v]];
            }
            if (tot%2==0 && cnt==tot/2){
                cout<<sum<<endl;
            } else {
                cout<<0<<endl;
            }
//            for (int i=1;i<=n;i++) cout<<i<<" "<<xr[i]<<" "<<ind[i]<<endl;
        } else {

//            A++;
//            if (A>10) exit(1);
            if (tot%2==0 && cnt==tot/2){
                vector<int>ans;
                for (int i=2;i<=n;i++){
                    if (xr[i]) ans.push_back(ind[i]);
                }
                sort(ans.begin(),ans.end());
                cout<<ans.size()<<" ";
                for (int i:ans) cout<<i<<" ";
                cout<<endl;
            } else {
                cout<<0<<endl;
            }

        }
    }






}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}