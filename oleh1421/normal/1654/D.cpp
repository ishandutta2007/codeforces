//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const int N=200010;
const ll mod=998244353;
//const int L=20;
const ll inv2=(mod+1)/2;
int p[N];
vector<pair<int,int> >L[N];
ll inv[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
ll a[N];
vector<pair<int,pair<ll,ll> > >g[N];
int pw[N];
int mx[N];
ll ans=1ll;
void upd(int pos,int val){
    pw[pos]+=val;
    mx[pos]=max(mx[pos],-pw[pos]);
}
ll val=1ll;
ll tot=0ll;
void dfs(int v,int pr){
    tot+=val;
    tot%=mod;
    for (auto cur:g[v]){
        int to=cur.first;
        ll x=cur.second.first;
        ll y=cur.second.second;
        if (to==pr) continue;
        for (auto d:L[y]){
            upd(d.first,d.second);
        }
        for (auto d:L[x]){
            upd(d.first,-d.second);
        }
        val*=y;
        val%=mod;
        val*=inv[x];
        val%=mod;
        dfs(to,v);
        val*=inv[y];
        val%=mod;
        val*=x;
        val%=mod;
        for (auto d:L[x]){
            upd(d.first,d.second);
        }
        for (auto d:L[y]){
            upd(d.first,-d.second);
        }
    }
}
void solve(){
    int n;cin>>n;
    ans=1ll;
    val=1ll;
    tot=0ll;
    for (int i=1;i<=n;i++) g[i].clear(),pw[i]=0,mx[i]=0;
    for (int i=1;i<n;i++){
        int a,b,x,y;cin>>a>>b>>x>>y;
//        int g=__gcd(x,y);
//        x/=g;
//        y/=g;
        g[a].push_back({b,{x,y}});
        g[b].push_back({a,{y,x}});
    }
    dfs(1,0);
    for (int i=1;i<=n;i++){
        ans*=binpow(i,mx[i]);
        ans%=mod;
    }
    cout<<tot*ans%mod<<endl;



}
int32_t main()
{
    for (int i=1;i<N;i++) p[i]=i;
    for (int i=2;i<N;i++){
        if (p[i]==i){
            for (int j=i*2;j<N;j+=i) p[j]=i;
        }
    }
    L[1]={};
    for (int i=2;i<N;i++){
        int cnt=0;
        int d=p[i];
        int x=i;
        while (x%d==0){
            x/=d;
            cnt++;
        }
        L[i]=L[x];
        L[i].push_back({d,cnt});
    }
    for (int i=1;i<N;i++) inv[i]=binpow(i,mod-2);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

//2
//
//1 2

/**


**/