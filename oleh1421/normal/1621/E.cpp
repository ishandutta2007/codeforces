#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
double random_double(){
    return rnd()%1000000001/1000000000.0;
}
const int N=201050;
int n,m;
ll k[N];
ll sum[N];
vector<ll>g[N];
ll a[N];
int cnt[N];
int last[N];
int get_ind(ll s,ll k){
    int ind=lower_bound(a+1,a+n+1,(s+k-1)/k)-a;
    return n-ind+1;
}
int t[N*4];
int w[N*4];
void build(int v,int l,int r){
    t[v]=w[v]=0;
    if (l==r) return;
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
}
void push(int v){
    t[v+v]+=w[v];
    t[v+v+1]+=w[v];
    w[v+v]+=w[v];
    w[v+v+1]+=w[v];
    w[v]=0;
}
void upd(int v,int l,int r,int L,int R,int x){
    if (l>R || r<L) return;
    if (l>=L && r<=R){
        t[v]+=x;
        w[v]+=x;
        return;
    }
    push(v);
    int m=(l+r)/2;
    upd(v+v,l,m,L,R,x);
    upd(v+v+1,m+1,r,L,R,x);
    t[v]=max(t[v+v],t[v+v+1]);
}
void solve(){
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];

    for (int i=1;i<=m;i++){
        cin>>k[i];
        sum[i]=0;
        g[i].clear();
        for (int j=1;j<=k[i];j++){
            ll x;cin>>x;
            sum[i]+=x;
            g[i].push_back(x);
        }
    }
    sort(a+1,a+n+1);

    for (int i=0;i<=n;i++) cnt[i]=0;
    build(1,0,n);
    for (int i=0;i<=n;i++) {
        cnt[i]--;
        upd(1,0,n,i,n,-1);
    }
    for (int i=1;i<=m;i++){
        last[i]=get_ind(sum[i],k[i]);
        cnt[last[i]]++;
        upd(1,0,n,last[i],n,1);

    }
    vector<int>ans;
    for (int i=1;i<=m;i++){
        cnt[last[i]]--;
        upd(1,0,n,last[i],n,-1);

        for (ll x:g[i]){
            int cur=get_ind(sum[i]-x,k[i]-1);
            cnt[cur]++;
            upd(1,0,n,cur,n,1);

            int mx=t[1];
            ans.push_back(mx<0);
            cnt[cur]--;
            upd(1,0,n,cur,n,-1);

        }
        cnt[last[i]]++;
        upd(1,0,n,last[i],n,1);

    }
    for (int i:ans) cout<<i;
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
2
0 0 4 2
0 0 2 4
4 2 4 2
2 4 2 4

**/