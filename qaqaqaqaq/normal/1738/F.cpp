#include<bits/stdc++.h>
#define int long long
using namespace std;


const int N=100007;
const int INF=LLONG_MAX/10;
const int mod=998244353;

int n;
int d[N],par[N],sz[N];
int fnd(int u){
    if (par[u]==u) return u;
    return par[u]=fnd(par[u]);
}
void unite(int u,int v){
    int pu=fnd(u), pv=fnd(v);
    if (pu==pv) return;
    if (sz[fnd(u)]==1) par[pu]=pv, sz[pv]+=sz[pu];
    else par[pv]=pu, sz[pu]+=sz[pv];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        for (int i=1;i<=n;++i) par[i]=i, sz[i]=1;
        for (int i=1;i<=n;++i) cin>>d[i];
        priority_queue<pair<int,int>> pq;
        for (int i=1;i<=n;++i) pq.push({d[i],i});
        while (pq.size()){
            auto [d,idx]=pq.top();
            pq.pop();
            while (par[idx]==idx&&d--){
                cout<<"? "<<idx<<endl;
                int u;
                cin>>u;
                assert(u!=-1);
                unite(u,idx);
            }
        } 
        cout<<"! ";
        for (int i=1;i<=n;++i) cout<<fnd(i)<<" ";
        cout<<endl;
    }
}