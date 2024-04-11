#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<pair<int,int> >q[1000001];
vector<int>g[1000001];
ll t[4000001];
int n;
void upd(int v,int l,int r,int pos,int x){
     if (l>pos || r<pos) return;
     if (l==r){
         t[v]+=x*1ll;
         return;
     }
     int m=(l+r)/2;
     upd(2*v,l,m,pos,x);
     upd(2*v+1,m+1,r,pos,x);
     t[v]=t[2*v]+t[2*v+1];
}
ll get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return 0ll;
    if (l>=L && r<=R) return t[v]*1ll;
    int m=(l+r)/2;
    return get(2*v,l,m,L,R)+get(2*v+1,m+1,r,L,R);
}
void add(int l,int r,int x){
     upd(1,1,n,l,x);
     if (r+1<=n) upd(1,1,n,r+1,-x);
}
ll val(int pos){
    return get(1,1,n,1,pos);
}
ll ans[1000001];
void dfs(int v,int pr,int h){
     for (auto cur:q[v]){
         add(h,h+cur.first,cur.second);
     }
     ans[v]=val(h);
     for (auto to:g[v]){
         if (to!=pr) dfs(to,v,h+1);
     }
     for (auto cur:q[v]){
         add(h,h+cur.first,-cur.second);
     }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int m;cin>>m;
    for (int i=1;i<=m;i++){
        int v,d,x;cin>>v>>d>>x;
        q[v].push_back({d,x});
    }
    dfs(1,0,1);
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}
//2 6 -2 -6  2