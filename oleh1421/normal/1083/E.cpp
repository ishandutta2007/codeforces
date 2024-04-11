#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000010;
const int T_SZ=N;
const ll mod=1000000007;
const ll inf=(1ll<<60);
//const ll inf=1000
ll s[N];
ll k[T_SZ];
ll b[T_SZ];
int L[T_SZ];
int R[T_SZ];
int TOT=1;
ll val(ll kk,ll bb,ll x){
    if (kk==mod && bb==mod) return -inf;
    return kk*x+bb;
}
void upd(int v,int l,int r,ll kk,ll bb,bool ok){
//    assert(v<=N);
    if (l==r){
        if (val(k[v],b[v],l)<val(kk,bb,l)){
            k[v]=kk;
            b[v]=bb;
        }
        return;
    }
    int m=(l+r)/2;
    int lef=(val(k[v],b[v],l)<val(kk,bb,l));
    int mid=(val(k[v],b[v],m)<val(kk,bb,m));
    if (mid){
        swap(k[v],kk);
        swap(b[v],bb);
    }
    if (kk==mod) return;
    if (lef!=mid){
        if (!L[v]){
            L[v]=++TOT;
            k[L[v]]=mod;
            b[L[v]]=mod;
        }
        upd(L[v],l,m,kk,bb,ok);
    } else {
        if (!R[v]){
            R[v]=++TOT;
            k[R[v]]=mod;
            b[R[v]]=mod;
        }
        upd(R[v],m+1,r,kk,bb,ok);
    }
}
ll get(int v,int l,int r,ll x){
//    assert(v<=N);
    if (!v) return -inf;
    if (l==r) return val(k[v],b[v],x);
    int m=(l+r)/2;
    if (x<=m) return max(val(k[v],b[v],x),get(L[v],l,m,x));
    else return max(val(k[v],b[v],x),get(R[v],m+1,r,x));
}
ll dp[N];
ll x[N];
ll y[N];
ll a[N];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    for (int i=0;i<T_SZ;i++){
//        k[i]=mod;
//        b[i]=mod;
//    }
    k[1]=mod;
    b[1]=mod;
    int n;cin>>n;
    vector<pair<pair<ll,ll>,ll> >v;
    for (int i=0;i<n;i++){
        ll x,y,z;cin>>x>>y>>z;
        v.push_back({{x,y},z});
    }
    sort(v.begin(),v.end());
    for (int i=0;i<n;i++){
        x[i+1]=v[i].first.first;
        y[i+1]=v[i].first.second;
        a[i+1]=v[i].second;
    }
    ll res=0ll;
    for (int i=1;i<=n;i++){
        dp[i]=x[i]*y[i]-a[i];
        dp[i]=max(dp[i],x[i]*y[i]-a[i]+get(1,0,1000000000,y[i]));
        res=max(res,dp[i]);
        upd(1,0,1000000000,-x[i],dp[i],0);
    }
//    assert(TOT<=N);
//    if (n>1000) res=TOT;
    cout<<res<<endl;


    return 0;
}