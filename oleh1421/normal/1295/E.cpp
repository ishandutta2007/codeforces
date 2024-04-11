//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//const ll mod=1000000007ll;
using namespace std;
#define endl '\n'
const int N=200010;
const int L=31;
ll suf[N];
ll t[N*4];
ll w[N*4];
int p[N];
ll a[N];
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
    t[v]=min(t[v+v],t[v+v+1]);
}
ll get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return 1000000000000001ll;
    if (l>=L && r<=R) return t[v];
    push(v);
    int m=(l+r)/2;
    return min(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
void solve(){
    int n;cin>>n;
    for (int i=0;i<=n+n+n+n;i++) t[i]=0ll,w[i]=0ll;
    for (int i=1;i<=n;i++){
        cin>>p[i];
    }
    for (int i=1;i<=n;i++) cin>>a[p[i]];
    for (int i=1;i<=n;i++){
        upd(1,1,n,1,i,a[i]);
    }
    ll sum=0ll;
    ll res=10000000000001ll;
    for (int i=n;i>=2;i--){
        upd(1,1,n,1,p[i],-2ll*a[p[i]]);
        sum+=a[p[i]]*1ll;
        //cout<<i<<" "<<get(1,1,n,1,n)<<" "<<sum<<endl;
        res=min(res,sum+min(0ll,get(1,1,n,1,n)));
    }
    cout<<res<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}