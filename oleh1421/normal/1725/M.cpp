#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,sse")
#include <bits/stdc++.h>
#define y1 y_1
//#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
#define prev aboba
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<vector<char> >frame;
const int N=600010;
const ll mod=998244353;
const ll inf=1e18;
vector<pair<int,ll> >g[N];
vector<pair<int,ll> >rg[N];
ll d[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        ll c;cin>>c;
        g[a].push_back({b,c});
        rg[b].push_back({a,c});
    }
    for (int i=1;i<=n;i++) d[i]=inf;
    d[1]=0;
    set<pair<ll,int> >st;
    for (int i=1;i<=n;i++) st.insert({d[i],i});
    while (!st.empty()){
        int v=(*st.begin()).second;
        st.erase(st.begin());
        for (auto [to,w]:g[v]){
            if (d[to]>d[v]+w){
                st.erase({d[to],to});
                d[to]=d[v]+w;
                st.insert({d[to],to});
            }
        }
    }
    for (int i=1;i<=n;i++) st.insert({d[i],i});
    while (!st.empty()){
        int v=(*st.begin()).second;
        st.erase(st.begin());
        for (auto [to,w]:rg[v]){
            if (d[to]>d[v]+w){
                st.erase({d[to],to});
                d[to]=d[v]+w;
                st.insert({d[to],to});
            }
        }
    }
    for (int i=2;i<=n;i++){
        if (d[i]==inf) d[i]=-1;
        cout<<d[i]<<" ";
    }
    cout<<endl;






}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;

    while (tt--){
        solve();
    }
    return 0;

}
///WRONG CYCLE
//124x
//xx3_
//xxxx



/*
4 4
bcex
adfd
gh_k
zghz
///0, 1, 2, 1, 2, 0, 2, 0, 1, 1, 2, 0, 2, 0, 1, 0, 1, 2, 2, 0, 1, 0, 1, 2, 1, 2, 0
1111111111111111111111111111111111111111111111111111111111111111
*/