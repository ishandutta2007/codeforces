#include<bits/stdc++.h>
typedef long long ll;

using namespace std;
#define endl '\n'
const ll mod=1000000007ll;
const int N=200010;
int x[N],y[N];
int L[N];
int R[N];
map<int,int>mpX;
map<int,int>mpY;
vector<pair<int,ll> >g[N];
ll dist[N];
void solve(){
    int n,m,sx,sy,fx,fy;cin>>n>>m>>sx>>sy>>fx>>fy;
    set<int>X,Y;
    for (int i=1;i<=m;i++){
        cin>>x[i]>>y[i];
        X.insert(x[i]);
        Y.insert(y[i]);
    }
    int szL=0;
    for (int i:X){
        L[++szL]=i;
        mpX[i]=szL;
    }
    int szR=0;
    for (int i:Y){
        R[++szR]=i;
        mpY[i]=szR;
    }
    for (int i=1;i<=szL;i++){
        dist[i]=abs(sx-L[i]);
    }
    for (int i=1;i<=szR;i++){
        dist[szL+i]=abs(sy-R[i]);
    }
    for (int i=1;i<szL;i++){
        g[i].push_back({i+1,L[i+1]-L[i]});
        g[i+1].push_back({i,L[i+1]-L[i]});
    }
    for (int i=1;i<szR;i++){
        g[i+szL].push_back({i+1+szL,R[i+1]-R[i]});
        g[i+1+szL].push_back({i+szL,R[i+1]-R[i]});
    }
    for (int i=1;i<=m;i++){
        g[mpX[x[i]]].push_back({mpY[y[i]]+szL,0});
        g[mpY[y[i]]+szL].push_back({mpX[x[i]],0});
    }
    set<pair<ll,int> >st;
    for (int i=1;i<=szL+szR;i++){
        st.insert({dist[i],i});
    }
    while (!st.empty()){
        int v=(*st.begin()).second;
        st.erase(st.begin());
        for (auto cur:g[v]){
            ll w=cur.second;
            int to=cur.first;
            if (dist[to]>dist[v]+w){
                st.erase({dist[to],to});
                dist[to]=dist[v]+w;
                st.insert({dist[to],to});
            }
        }
    }
    ll res=abs(sx-fx)+abs(sy-fy);
    for (int i=1;i<=m;i++){
        res=min(res,abs(x[i]-fx)+abs(y[i]-fy)+dist[mpX[x[i]]]);
    }
    cout<<res<<endl;





}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
///try to solve I
///try to solve B(Two sets)
/*
)()(()
*/