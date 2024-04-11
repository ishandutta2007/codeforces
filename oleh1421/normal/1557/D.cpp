//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define double long double
using namespace std;
const int N=600010;
const ll mod=1000000007;
vector<pair<int,int> >seg[N];
pair<int,int>t[N*4];
pair<int,int>w[N*4];
void push(int v){
    t[v+v]=max(t[v+v],w[v]);
    t[v+v+1]=max(t[v+v+1],w[v]);
    w[v+v]=max(w[v+v],w[v]);
    w[v+v+1]=max(w[v+v+1],w[v]);
    w[v]={0,0};
}
void upd(int v,int l,int r,int L,int R,pair<int,int>x){
    if (l>R || r<L) return;
    if (l>=L && r<=R){
        t[v]=max(t[v],x);
        w[v]=max(w[v],x);
        return;
    }
    int m=(l+r)/2;
    push(v);
    upd(v+v,l,m,L,R,x);
    upd(v+v+1,m+1,r,L,R,x);
    t[v]=max(t[v+v],t[v+v+1]);
}
pair<int,int>get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return {0,0};
    if (l>=L && r<=R) return t[v];
    push(v);
    int m=(l+r)/2;
    return max(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
int dp[N],p[N];
bool need[N];
void solve(){
    int n,m;cin>>n>>m;
    set<int>st;
    for (int i=1;i<=m;i++){
        int j,l,r;cin>>j>>l>>r;
        st.insert(l);
        st.insert(r);
        seg[j].push_back({l,r});
    }
    map<int,int>mp;
    int cnt=0;
    for (int x:st){
        mp[x]=++cnt;
    }
    for (int i=1;i<=n;i++){
        for (auto &cur:seg[i]){
            cur.first=mp[cur.first];
            cur.second=mp[cur.second];
        }
    }
    for (int i=1;i<=n;i++){
        pair<int,int>mx={0,0};
        for (auto cur:seg[i]){
            mx=max(mx,get(1,1,cnt,cur.first,cur.second));
        }
        dp[i]=mx.first+1;
        p[i]=mx.second;
        mx={dp[i],i};
        for (auto cur:seg[i]){
            upd(1,1,cnt,cur.first,cur.second,mx);
        }
    }
    int mx=0;
    for (int i=1;i<=n;i++){
        if (dp[i]>dp[mx]) mx=i;
    }
    int res=n-dp[mx];
    while (mx){
        need[mx]=true;
        mx=p[mx];
    }
    cout<<res<<endl;
    for (int i=1;i<=n;i++){
        if (!need[i]) cout<<i<<" ";
    }
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}